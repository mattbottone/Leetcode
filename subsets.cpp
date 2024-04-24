class Solution {
private:
    vector<vector<int>> solution;
    vector<int> subset;

    void dfs(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            solution.push_back(subset);
            return;
        }

        //include segment of backtracking
        subset.push_back(nums[i]);
        dfs(i+1, nums);

        //exclude segment of backtracking
        subset.pop_back();
        dfs(i+1, nums);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return solution;
    }
};
