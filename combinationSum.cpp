class Solution {
private:
    vector<vector<int>> solutions;
    vector<int> subset;

    void dfs(vector<int>& candidates, int target, int i, int sum) {
        if (sum == target) {
            solutions.push_back(subset);
            return;
        }
        else if (i >= candidates.size() || sum > target) return;

        subset.push_back(candidates[i]);
        dfs(candidates, target, i, sum + candidates[i]);

        subset.pop_back();
        dfs(candidates, target, i + 1, sum);

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return solutions;
    }
};
