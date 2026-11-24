class Solution {
private:
    unordered_map<Node*, Node*> cloned;

    Node* dfs(Node* node) {
        if (!node) {
            return nullptr;
        }
        auto it = cloned.find(node);
        if (it != cloned.end()) {
            return it->second;
        }

        Node* copy = new Node(node->val);
        cloned[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor));
        }

        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
