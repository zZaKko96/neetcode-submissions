class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right =  *ranges::max_element(piles);
        int answer = right;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int total_hours = 0;
            for (const int i : piles)
                total_hours += (i + mid - 1) / mid;
            if (total_hours <= h)
            {
                answer = min(answer, mid);
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return answer;
    }
};