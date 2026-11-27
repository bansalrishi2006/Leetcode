class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    TrieNode* findNode(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return nullptr;
            }
            curr = curr->children[idx];
        }
        return curr;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = findNode(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return findNode(prefix) != nullptr;
    }
};
