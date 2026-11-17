class Solution {
private:
    unordered_map<int, int> inorderIndexMap;
    int postorderIndex;

    TreeNode* helper(const vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndexMap[rootVal];

        root->right = helper(postorder, mid + 1, right);
        root->left = helper(postorder, left, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex = postorder.size() - 1;
        inorderIndexMap.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        return helper(postorder, 0, inorder.size() - 1);
    }
};
