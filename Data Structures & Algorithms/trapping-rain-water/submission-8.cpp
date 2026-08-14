class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0;
        int right = height.size() - 1;
        int totalWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                int level = height[left];
                left++;
                while (left < right && height[left] <= level) {
                    totalWater += level - height[left];
                    left++;
                }
            }
            else {
                int level = height[right];
                right--;
                while (left < right && height[right] <= level) {
                    totalWater += level - height[right];
                    right--;
                }
            }
        }

        return totalWater;
    }
};