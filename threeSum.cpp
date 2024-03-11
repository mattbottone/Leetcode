#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        int middle = 1;
        int right = nums.size() - 1;

        for (int left = 0; left < nums.size()-2; left++) {
            if (left > 0 && nums[left] == nums[left - 1]) continue;

            int middle = left + 1;
            int right = nums.size() - 1;

            while (middle < right) {
                int sum = nums[left] + nums[middle] + nums[right];

                if (sum > 0) right--;
                else if (sum < 0) middle++;
                else if (sum == 0) {
                    solution.push_back({nums[left], nums[middle], nums[right]});
                    while (middle < right && nums[middle] == nums[middle+1]) middle++;
                    while (middle < right && nums[right] == nums[right-1]) right--;
                    right--;
                    middle++;
                }
            }
        }
        return solution;
    }
};
