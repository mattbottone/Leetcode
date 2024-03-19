#include <algorithm>
#include <vector>
#include <cmath>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(begin(piles), end(piles));
        int answer = right;
        int k;
        long hours;

        while (left <= right) {
            k = (left + right) / 2;
            hours = 0;

            for (int i = 0; i < piles.size(); i++){
                hours += ceil((double)piles[i] / k);
            }

            if (hours <= h) {
                answer = min(answer, k);
                right = k - 1;
            }
            else left = k + 1;
        }

        return answer;

    }
};
