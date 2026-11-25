class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (static_cast<int>(order.size()) == numCourses) {
            return order;
        }
        return {};
    }
};
