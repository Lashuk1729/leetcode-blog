class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit, t_profit, buy;
        max_profit = 0;
        t_profit = 0;
        buy = INT_MIN;
        for(int i = 0; i < prices.size(); i++)
        {
            if(-1*prices[i] > buy)
                buy = -1 * prices[i];
            
            t_profit = prices[i] + buy;
            if(t_profit >= max_profit)
                max_profit = t_profit;
        }
        return max_profit;
    }
};