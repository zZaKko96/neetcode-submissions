class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int i : nums)
            if (!mySet.insert(i).second)
                return i;
    }
};