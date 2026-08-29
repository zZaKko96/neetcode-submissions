class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int midIndex = left + (right - left) / 2;
            if (nums[midIndex] > nums[right])
                left = midIndex + 1;
            else
                right = midIndex;
        }

        return nums[left];
    }
};