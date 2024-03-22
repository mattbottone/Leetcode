#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> substring;
        int left = 0, result = 0, windowSize = 0, maxCount = 0;

        for (int right = 0; right < s.size(); right++) {
            //iterate substring value and update maxChar
            maxCount = max(maxCount, ++substring[s[right]]);

            windowSize = (right - left + 1);

            //move window if collisions exceed 'k'
            while (windowSize - maxCount > k) {
                substring[s[left]]--;
                left++;
                windowSize = (right - left + 1);
            }

            result = max(result, windowSize);
        }
        return result;
    }
};
