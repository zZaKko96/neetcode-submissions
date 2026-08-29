class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            int leftNum = nums[left];
            int rightNum = nums[right];
            int midIndex = left + (right - left) / 2;
            int midNum = nums[midIndex];

            if (target == midNum) {
                return midIndex;
            }

            if (leftNum <= midNum) {
                if (target >= leftNum && target < midNum) {
                    right = midIndex - 1;
                }
                else {
                    left = midIndex + 1;
                }
            }
            else {
                if (target > midNum && target <= rightNum) {
                    left = midIndex + 1;
                }
                else {
                    right = midIndex - 1;
                }
            }
        }

        return -1;
    }
};