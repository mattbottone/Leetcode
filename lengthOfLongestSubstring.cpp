// leetcode:
// 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int length = s.length();
        int longestSubstring = 0;
        int left = 0;

        for (int right = 0; right < length; right++) {
            if (set.count(s[right]) == 0) {
                set.insert(s[right]);
                longestSubstring = max(longestSubstring, right - left + 1);
            }
            else {
                while (set.count(s[right])) {
                    set.erase(s[left]);
                    left++;
                }
                set.insert(s[right]);
            }
        }

        return longestSubstring;
    }
};
