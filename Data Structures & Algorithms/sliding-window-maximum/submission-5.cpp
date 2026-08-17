class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        size_t size = nums.size();

        vector<bool> BitsForNumbers(size, false);

        vector<int> MaxElementEachStep;
        MaxElementEachStep.reserve(size - k + 1);

        deque<size_t> bufferOfIndexes;
        
        size_t left = 0, right = 0;

        bufferOfIndexes.push_back(right);
        right++;
        for (; right < k; right++)
        {
            while (!bufferOfIndexes.empty() && nums[right] > nums[bufferOfIndexes.back()])
            {
                BitsForNumbers[bufferOfIndexes.back()] = true;
                bufferOfIndexes.pop_back();
            }

            bufferOfIndexes.push_back(right);
        }

        MaxElementEachStep.push_back(nums[bufferOfIndexes.front()]);

        for (; right < size; left++, right++)
        {
            if (auto it = ranges::find(bufferOfIndexes, left); it != bufferOfIndexes.end() && !BitsForNumbers[left])
                bufferOfIndexes.erase(it);

            while (!bufferOfIndexes.empty() && nums[right] > nums[bufferOfIndexes.back()])
            {
                BitsForNumbers[bufferOfIndexes.back()] = true;
                bufferOfIndexes.pop_back();
            }

            bufferOfIndexes.push_back(right);

            MaxElementEachStep.push_back(nums[bufferOfIndexes.front()]);
        }

        return MaxElementEachStep;
    }
};