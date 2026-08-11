class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> myMap;
        size_t n = position.size();
        
        for (size_t i = 0; i < n; i++)
            myMap[position[i]] = speed[i];
        
        vector<double> times;
        times.reserve(n);

        for (const auto&[pos,spd] : myMap)
        {
            double time = static_cast<double>(target - pos) / spd;

            if (!times.empty() && time <= times.back()) continue;
            times.push_back(time);
        }

        return times.size();
    }
};