class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<10000> bits;
        
        for (const int i : nums)
        {
            if (bits.test(i - 1)) return i;
            bits.set(i - 1);
        }
    }
};