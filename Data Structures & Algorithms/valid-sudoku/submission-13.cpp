class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        uint16_t rows[9]{ 0 };
        uint16_t columns[9]{ 0 };
        uint16_t blocks[9]{ 0 };

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                uint16_t mask = 1 << (board[i][j] - '1');
                int block_idx = (i / 3) * 3 + (j / 3);

                if ((rows[i] & mask) || (columns[j] & mask) || (blocks[block_idx] & mask)) {
                    return false;
                }

                rows[i] |= mask;
                columns[j] |= mask;
                blocks[block_idx] |= mask;
            }
        }

        return true;
    }
};