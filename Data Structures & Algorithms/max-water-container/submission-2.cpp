class Solution {
public:
    int maxArea(vector<int>& heights) {
        int answer = 0;
        int i = 0, j = heights.size() - 1;

        while (i < j) {
            int h = min(heights[i], heights[j]);
            answer = max(answer, (j - i) * h);

            while (i < j && heights[i] <= h) i++;
            while (i < j && heights[j] <= h) j--;
        }

        return answer;
    }
};