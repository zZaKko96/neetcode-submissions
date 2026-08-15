class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int minValue = prices[0];

        for (auto it = prices.begin()+1; it != prices.end(); it++)
        {
            minValue = min(minValue, *it);
            profit = max(profit, *it - minValue);
        }

        return profit;
    }
};