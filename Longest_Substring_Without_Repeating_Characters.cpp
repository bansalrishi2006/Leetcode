#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> charMap(128, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            if (charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }

            charMap[s[right]] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    std::cout << solution.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << solution.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << solution.lengthOfLongestSubstring("pwwkew") << std::endl;

    return 0;
}