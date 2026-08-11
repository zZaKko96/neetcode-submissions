class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> myVec;
        size_t n = position.size();
        myVec.reserve(n);
        
        for (size_t i = 0; i < n; i++)
            myVec.emplace_back(position[i], speed[i]);

        sort(myVec.begin(), myVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first > b.first; });
        
        size_t count = 0;
        double lastTime = 0;

        for (const auto&[pos,spd] : myVec)
        {
            double time = (double)(target - pos) / spd;

            if (time <= lastTime) continue;
            lastTime = time;
            count++;
        }

        return count;
    }
};