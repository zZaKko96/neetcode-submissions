class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        set.reserve(nums.size());

        for (int i : nums)
        {
            auto [iter, inserted] = set.insert(i);
            if (!inserted) return true;
        }
        return false;
    }
};