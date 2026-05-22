class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = 0, maxProfit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(i == 1)
            {
                minPrice = prices[i-1];
                maxProfit = minPrice - prices[i-1];
            }
            if(minPrice > prices[i-1])
                minPrice = prices[i-1];

            int profit = (prices[i] - minPrice);
            if( profit > maxProfit)
                maxProfit = profit;
        }

        if(maxProfit < 0) maxProfit = 0;
        return maxProfit;
    }
};
