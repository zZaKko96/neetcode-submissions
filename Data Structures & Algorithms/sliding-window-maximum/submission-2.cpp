class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> MaxElementEachStep;
        MaxElementEachStep.reserve(nums.size());

        multiset<int,greater<int>> maximuses;
        auto left = nums.begin(), right = nums.begin();

        for (size_t i = 0; i < k; i++, right++)
            maximuses.insert(*right);

        for (; right != nums.end(); left++, right++)
        {
            MaxElementEachStep.push_back(*maximuses.begin());
            maximuses.erase(maximuses.find(*left));
            maximuses.insert(*right);
        }

        MaxElementEachStep.push_back(*maximuses.begin());

        return MaxElementEachStep;
    }
};