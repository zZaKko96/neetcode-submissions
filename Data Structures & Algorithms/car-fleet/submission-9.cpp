class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> myMap;
        size_t n = position.size();
        
        for (size_t i = 0; i < n; i++)
            myMap[position[i]] = speed[i];
        
        size_t count = 0;
        double lastTime = 0;

        for (const auto&[pos,spd] : myMap)
        {
            double time = (double)(target - pos) / spd;

            if (time <= lastTime) continue;
            lastTime = time;
            count++;
        }

        return count;
    }
};