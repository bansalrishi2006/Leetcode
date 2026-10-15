class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
        int i = n - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i < 0) break;
            
            int j = i;
            while (i >= 0 && s[i] != ' ') {
                i--;
            }
            
            string word = s.substr(i + 1, j - i);
            if (result.empty()) {
                result = word;
            } else {
                result += " " + word;
            }
        }

        return result;
    }
};
