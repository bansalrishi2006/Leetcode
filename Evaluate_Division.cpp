#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    double dfs(const string& curr, const string& target,
               unordered_map<string, unordered_map<string, double>>& adj,
               unordered_set<string>& visited) {
        if (curr == target) {
            return 1.0;
        }
        visited.insert(curr);
        for (const auto& [neighbor, weight] : adj[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                double res = dfs(neighbor, target, adj, visited);
                if (res != -1.0) {
                    return weight * res;
                }
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        for (size_t i = 0; i < equations.size(); ++i) {
            const string& u = equations[i][0];
            const string& v = equations[i][1];
            double val = values[i];
            adj[u][v] = val;
            adj[v][u] = 1.0 / val;
        }

        vector<double> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            const string& src = q[0];
            const string& dst = q[1];

            if (adj.find(src) == adj.end() || adj.find(dst) == adj.end()) {
                ans.push_back(-1.0);
            } else if (src == dst) {
                ans.push_back(1.0);
            } else {
                unordered_set<string> visited;
                ans.push_back(dfs(src, dst, adj, visited));
            }
        }

        return ans;
    }
};
