class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for (int num : nums) {
            myMap[num]++;
        }

        vector<vector<int>> myVec(nums.size() + 1);
        for (const auto& [num, count] : myMap) {
            myVec[count].push_back(num);
        }

        vector<int> answer;
        answer.reserve(k);

        for (int i = myVec.size() - 1; i >= 0; --i) {
            for (int num : myVec[i]) {
                answer.push_back(num);
                if (answer.size() == k) {
                    return answer;
                }
            }
        }

        return answer;
    }
};