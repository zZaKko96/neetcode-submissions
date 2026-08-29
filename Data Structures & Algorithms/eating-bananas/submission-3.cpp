class Solution {
private:
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long total_hours = 0;
        for (const int count : piles) {
            total_hours += (count + k - 1) / k;
            if (total_hours > h) {
                return false;
            }
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *ranges::max_element(piles);
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid)) {
                answer = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return answer;
    }
};