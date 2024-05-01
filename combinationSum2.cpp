class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> solution;
        dfs(solution, candidates, 0, target);
        return solution;
    }
private:
    vector<int> subset;
    int sum = 0;

    void dfs(vector<vector<int>>& solution, vector<int>& candidates, int depth, int target) {
        if (sum == target) {
            solution.push_back(subset);
            return;
        }
        else if (depth >= candidates.size() || sum > target) return;

        subset.push_back(candidates[depth]);
        sum += candidates[depth];
        dfs(solution, candidates, depth+1, target);

        subset.pop_back();
        sum -= candidates[depth];
        while (depth+1 < candidates.size() && candidates[depth] == candidates[depth+1]) {
            depth++;
        }
        dfs(solution, candidates, depth+1, target);

    }
};
