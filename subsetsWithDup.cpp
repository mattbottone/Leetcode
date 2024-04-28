#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        solution.push_back(vector<int>());
        vector<int> subset;
        dfs(nums, 0, subset, solution);
        return solution;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& solution) {
        if (start == nums.size()) {
            if (duplicateSearch(solution, subset)) {
                solution.push_back(subset);
            }
            return;
        }
        subset.push_back(nums[start]);
        dfs(nums, start+1, subset, solution);
        subset.pop_back();
        dfs(nums, start+1, subset, solution);
    }
    bool duplicateSearch(vector<vector<int>>& solution, vector<int> candidate) {
        auto test = find(solution.begin(), solution.end(), candidate);
        if (test == solution.end()) return true;
        else return false;
    }
};
