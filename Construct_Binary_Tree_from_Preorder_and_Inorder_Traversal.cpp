class Solution {
private:
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int mid = inorderMap[rootValue];

        root->left = arrayToTree(preorder, left, mid - 1);
        root->right = arrayToTree(preorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        inorderMap.clear();
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, inorder.size() - 1);
    }
};
