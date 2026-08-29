class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        int i = -1, j = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[mid][j] == target)
                return true;
            else if (matrix[mid][j] < target)
            {
                i = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        if (i == -1) return false;

        left = 0;
        right = matrix[i].size() - 1;

        while (left <= right)
        {
            j = left + (right - left) / 2;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                right = j - 1;
            else
                left = j + 1;
        }
        
        return false;
    }
};