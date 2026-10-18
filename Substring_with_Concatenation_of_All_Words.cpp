class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seenWords;
            int count = 0;

            while (right + wordLen <= sLen) {
                string sub = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.find(sub) != wordCount.end()) {
                    seenWords[sub]++;
                    count++;

                    while (seenWords[sub] > wordCount[sub]) {
                        string leftSub = s.substr(left, wordLen);
                        seenWords[leftSub]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
