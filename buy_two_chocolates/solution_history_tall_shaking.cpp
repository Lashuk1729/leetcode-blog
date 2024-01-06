#pragma GCC optimize("03","unroll-loops")

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min_price1 = INT_MAX, min_price2 = INT_MAX, n = prices.size();
        for(int i = 0; i < n; i++) {
            if(prices[i] < min_price1) {
                min_price2 = min_price1;
                min_price1 = prices[i];
            }
            else if(min_price2 > prices[i])
                min_price2 = prices[i];
        }
        return min_price1 + min_price2 <= money ? money - (min_price1 + min_price2) : money;  
    }
};