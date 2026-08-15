class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (size_t left = 0, right = 1; right < prices.size(); right++)
        {
            if (prices[left] > prices[right])
                left = right;
            else if (int newProfit = prices[right] - prices[left];newProfit > profit)
                profit = newProfit;
        }

        return profit;
    }
};