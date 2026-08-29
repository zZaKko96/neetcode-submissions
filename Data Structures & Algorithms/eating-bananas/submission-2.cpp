class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right =  *ranges::max_element(piles);
        int answer = right;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            long long total_hours = 0;
            for (const int i : piles)
            {
                total_hours += (i + mid - 1) / mid;
                if (total_hours > h)
                {
                    left = mid + 1;
                    goto new_cycle;
                }
            }
            answer = min(answer, mid);
            right = mid - 1;
            new_cycle:
        }
        return answer;
    }
};