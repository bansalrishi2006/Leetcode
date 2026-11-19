class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        if (topNode->right != nullptr) {
            pushLeft(topNode->right);
        }
        return topNode->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
