class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;

        while (m >= 0) {
            if (target < matrix[m][0]) m--;
            else {
                for (int x = 0; x <= n; x++) {
                    if (matrix[m][x] == target) return true;
                }
                return false;
            }
        }
        return false;

    }
};
