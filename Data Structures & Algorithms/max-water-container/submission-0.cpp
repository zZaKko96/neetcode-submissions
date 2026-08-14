class Solution {
public:
    int maxArea(vector<int>& heights) {
        int answer = 0;

        for (int i = 0, j = heights.size() - 1; i < j;)
        {
            answer = max((j - i) * min(heights[i], heights[j]), answer);
            if (heights[i] >= heights[j]) j--;
            else i++;
        }

        return answer;
    }
};