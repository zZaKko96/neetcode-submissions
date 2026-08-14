class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() - 1;
        int left = 0, right = n;
        int leftMax = height[0], rightMax = height[n], totalWater = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if(leftMax > height[left])
                    totalWater += leftMax - height[left];
                left++;
                leftMax = max(leftMax, height[left]);
            }
            else
            {
                if(rightMax > height[right])
                    totalWater += rightMax - height[right];
                right--;
                rightMax = max(rightMax, height[right]);
            }
        }

        return totalWater;
    }
};