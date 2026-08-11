class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        size_t n = position.size();
        if (n == 0) return 0;

        vector<pair<int, int>> cars;
        cars.reserve(n);

        for (size_t i = 0; i < n; i++) {
            cars.emplace_back(position[i], speed[i]);
        }

        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
            });

        int count = 0;
        long long maxDist = 0;
        long long maxSpeed = 1;

        for (const auto& [pos, spd] : cars) {
            long long curDist = target - pos;
            long long curSpeed = spd;

            if (count != 0 && curDist * maxSpeed <= maxDist * curSpeed) {
                continue;
            }

            maxDist = curDist;
            maxSpeed = curSpeed;
            count++;
        }

        return count;
    }
};