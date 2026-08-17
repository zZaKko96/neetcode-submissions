class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        size_t size = nums.size();

        vector<int> MaxElementEachStep(size - k + 1);
        auto frontMaxElementEachStep = MaxElementEachStep.begin();

        vector<int32_t> buffer(size);
        size_t head = 0, tail = 0;

        auto left = nums.begin(), right = nums.begin();

        for (size_t i = 0; i < k; i++, right++)
        {
            while (head < tail && *right > buffer[tail - 1])
                tail--;

            buffer[tail++] = *right;
        }

        *frontMaxElementEachStep++ = buffer[head];

        for (; right != nums.end(); left++, right++)
        {
            if (*left == buffer[head])
                head++;

            while (head < tail && *right > buffer[tail - 1])
                tail--;

            buffer[tail++] = *right;

            *frontMaxElementEachStep++ = buffer[head];
        }

        return MaxElementEachStep;
    }
};