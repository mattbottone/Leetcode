class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9), col(9), box(9);

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){

                if (board[i][j] == '.') continue; //check if empty cell

                int index = board[i][j] - '0'; //convert board index to int
                int boxNum = (i/3) * 3 + j/3;

                //check for duplicate characters within each row, column, and box
                if (row[i].count(index) || col[j].count(index) || box[boxNum].count(index)) {
                    return false;
                }

                row[i].insert(index);
                col[j].insert(index);
                box[boxNum].insert(index);
            }
        }
        return true;
    }
};
