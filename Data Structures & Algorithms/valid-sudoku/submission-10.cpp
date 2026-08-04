class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        uint16_t rows[9]{ 0 };
        uint16_t columns[9]{ 0 };
        uint16_t blocks[9]{ 0 };
        for(size_t i = 0; i < 9; i++)
            for (size_t j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;

                if (rows[i] & (1 << board[i][j] - '0' - 1)) return false;
                else rows[i] |= 1 << board[i][j] - '0' - 1;

                if (columns[j] & (1 << board[i][j] - '0' - 1)) return false;
                else columns[j] |= (1 << board[i][j] - '0' - 1);

                if (blocks[(i / 3) * 3 + (j / 3)] & (1 << board[i][j] - '0' - 1)) return false;
                else blocks[(i / 3) * 3 + (j / 3)] |= (1 << board[i][j] - '0' - 1);
            }
        return true;
    }
};
