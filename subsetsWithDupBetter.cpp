#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> subset;
        vector<vector<int>> solution;

        dfs(nums, 0, subset, solution);
        return solution;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& solution) {
        if (start == nums.size()) {
            solution.push_back(subset);
            return;
        }
        subset.push_back(nums[start]);
        dfs(nums, start+1, subset, solution);

        subset.pop_back();
        while (start+1 < nums.size() && nums[start] == nums[start+1]) {
            start++; //skip duplicates that are already accounted for
        }
        dfs(nums, start+1, subset, solution);
    }
};
