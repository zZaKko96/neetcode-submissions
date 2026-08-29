class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m*n-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int num = matrix[mid / n][mid % n];
            if (target == num)
                return true;
            else if (target > num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return false;
    }
};