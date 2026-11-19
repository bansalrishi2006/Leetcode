class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight = 0;
        TreeNode* curr = root;
        while (curr) {
            leftHeight++;
            curr = curr->left;
        }

        int rightHeight = 0;
        curr = root;
        while (curr) {
            rightHeight++;
            curr = curr->right;
        }

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
