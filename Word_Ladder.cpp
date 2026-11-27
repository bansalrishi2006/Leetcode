class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) {
                return steps;
            }

            for (int i = 0; i < static_cast<int>(word.size()); ++i) {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) {
                        continue;
                    }
                    word[i] = c;
                    if (dict.find(word) != dict.end()) {
                        q.push({word, steps + 1});
                        dict.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }

        return 0;
    }
};
