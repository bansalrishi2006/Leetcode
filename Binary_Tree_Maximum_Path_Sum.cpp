class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode* node, int& ans) {
        if (!node) {
            return 0;
        }
        int leftGain = max(0, dfs(node->left, ans));
        int rightGain = max(0, dfs(node->right, ans));
        ans = max(ans, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain);
    }
};
