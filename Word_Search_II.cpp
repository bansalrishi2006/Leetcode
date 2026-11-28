class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word;
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& ans) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) {
            return;
        }

        node = node->children[ch - 'a'];
        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word.clear();
        }

        board[r][c] = '#';

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < static_cast<int>(board.size()) &&
                nc >= 0 && nc < static_cast<int>(board[0].size())) {
                dfs(board, nr, nc, node, ans);
            }
        }

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            insertWord(root, w);
        }

        vector<string> ans;
        for (int r = 0; r < static_cast<int>(board.size()); ++r) {
            for (int c = 0; c < static_cast<int>(board[0].size()); ++c) {
                dfs(board, r, c, root, ans);
            }
        }

        return ans;
    }
};
