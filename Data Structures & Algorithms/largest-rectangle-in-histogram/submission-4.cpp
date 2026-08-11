class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> st;
        st.reserve(n);

        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currentHeight < heights[st.back()]) {
                int h = heights[st.back()];
                st.pop_back();

                int width = st.empty() ? i : (i - st.back() - 1);
                maxArea = max(maxArea, h * width);
            }

            st.push_back(i);
        }

        return maxArea;
    }
};