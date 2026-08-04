class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        set<int> mySet(nums.begin(), nums.end());

        int maxCount = 1, count = 1;
        for (auto it = next(mySet.begin()); it != mySet.end(); it++)
        {
            if (*it - *prev(it) == 1)
            {
                count++;
                if (count > maxCount) maxCount = count;
            }
            else count = 1;
        }

        return maxCount;
    }
};