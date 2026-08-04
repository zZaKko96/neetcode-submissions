class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<unordered_set<char>, 9> rows;
        array<unordered_set<char>, 9> columns;
        array<unordered_set<char>, 9> blocks;
        for(size_t i = 0; i < 9; i++)
            for (size_t j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                if (!rows[i].insert(board[i][j]).second) return false;
                if (!columns[j].insert(board[i][j]).second) return false;
                if (!blocks[(i / 3) * 3 + (j / 3)].insert(board[i][j]).second) return false;
            }
        return true;
    }
};