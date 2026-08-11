class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> myVec;
        size_t n = heights.size();
        myVec.reserve(n);

        int maxArea = 0;

        for (int i = 0; i < static_cast<int>(n); i++) {
            int startIndex = i;

            while (!myVec.empty() && heights[i] < myVec.back().second) {
                int currentHeight = myVec.back().second;
                int currentStartIndex = myVec.back().first;

                int currentArea = currentHeight * (i - currentStartIndex);
                maxArea = max(maxArea, currentArea);

                startIndex = currentStartIndex;
                myVec.pop_back();
            }

            myVec.emplace_back(startIndex, heights[i]);
        }

        while (!myVec.empty()) {
            int currentHeight = myVec.back().second;
            int currentStartIndex = myVec.back().first;

            int currentArea = currentHeight * (static_cast<int>(n) - currentStartIndex);
            maxArea = max(maxArea, currentArea);

            myVec.pop_back();
        }

        return maxArea;
    }
};