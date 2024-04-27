#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;
        dfs(nums, 0, solution);
        return solution;
    }
private:
    void dfs(vector<int>& nums, int start, vector<vector<int>>& solution) {
        if (start == nums.size()) {
            solution.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1, solution);
            swap(nums[i], nums[start]);
        }
    }
};
