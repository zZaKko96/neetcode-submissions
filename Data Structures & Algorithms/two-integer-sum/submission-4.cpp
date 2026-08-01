class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> myMap;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            auto it = myMap.find(complement);
            if (it != myMap.end()) {
                return { it->second, i };
            }

            myMap.emplace(nums[i], i);
        }

        return {};
    }
};