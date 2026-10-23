class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : mp) {
            result.push_back(pair.second);
        }
        return result;
    }
};
