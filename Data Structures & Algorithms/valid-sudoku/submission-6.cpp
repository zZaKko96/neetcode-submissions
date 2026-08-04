class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9]{ false };
        bool columns[9][9]{ false };
        bool blocks[9][9]{ false };
        for(size_t i = 0; i < 9; i++)
            for (size_t j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;

                if (rows[i][board[i][j]-'0'-1]) return false;
                else rows[i][board[i][j] - '0' - 1] = true;

                if (columns[j][board[i][j] - '0' - 1]) return false;
                else columns[j][board[i][j] - '0' - 1] = true;

                if (blocks[(i / 3) * 3 + (j / 3)][board[i][j] - '0' - 1]) return false;
                else blocks[(i / 3) * 3 + (j / 3)][board[i][j] - '0' - 1] = true;
            }
        return true;
    }
};