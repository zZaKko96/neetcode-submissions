class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answers(n, 0);

        for (int i = n - 2; i >= 0; --i) {
            int j = i + 1;

            while (j < n && temperatures[j] <= temperatures[i]) {
                if (answers[j] == 0) {
                    j = n;
                    break;
                }
                j += answers[j];
            }

            if (j < n) {
                answers[i] = j - i;
            }
        }

        return answers;
    }
};