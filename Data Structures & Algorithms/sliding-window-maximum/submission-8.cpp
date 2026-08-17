class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> MaxElementEachStep;
        MaxElementEachStep.reserve(nums.size() - k + 1);

        deque<int32_t> buffer;
        
        auto left = nums.begin(), right = nums.begin();

        for (size_t i = 0; i < k; i++, right++)
        {
            while (!buffer.empty() && *right > buffer.back())
                buffer.pop_back();

            buffer.push_back(*right);
        }

        MaxElementEachStep.push_back(buffer.front());

        for (; right != nums.end(); left++, right++)
        {
            if (*left == buffer.front())
                buffer.pop_front();

            while (!buffer.empty() && *right > buffer.back())
                buffer.pop_back();

            buffer.push_back(*right);

            MaxElementEachStep.push_back(buffer.front());
        }

        return MaxElementEachStep;
    }
};