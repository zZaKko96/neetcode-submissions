class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> bits(nums.size(), 0);
        
        for (const int i : nums)
        {
            if (bits[i-1]) return i;
            bits[i-1] = true;
        }
    }
};