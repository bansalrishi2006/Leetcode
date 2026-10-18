class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> targetFreq(128, 0);
        for (char c : t) {
            targetFreq[c]++;
        }

        int required = 0;
        for (int i = 0; i < 128; i++) {
            if (targetFreq[i] > 0) {
                required++;
            }
        }

        int l = 0, r = 0;
        int formed = 0;
        vector<int> windowFreq(128, 0);
        
        int minLen = INT_MAX;
        int minLeft = 0;

        while (r < s.length()) {
            char c = s[r];
            windowFreq[c]++;

            if (targetFreq[c] > 0 && windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minLeft = l;
                }

                char leftChar = s[l];
                windowFreq[leftChar]--;
                if (targetFreq[leftChar] > 0 && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;
                }
                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
