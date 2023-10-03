class Solution {
public:
    int solve(vector<int>&prices, int index, int buy,vector<vector<int>>&DP, int fee){
        if(index==prices.size()){
            return 0;
        }
        if(DP[index][buy] != -1){
            return DP[index][buy];
            
        }
        
        int profit =0;
        if(buy){
            int buyKaro = -prices[index] + solve(prices, index+1, 0,DP, fee);
            int skipKaro = solve(prices, index+1, 1, DP, fee);
            
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] + solve(prices, index+1, 1, DP, fee) - fee;
            int skipKaro = solve(prices, index+1, 0, DP, fee);
            
            profit = max(sellKaro, skipKaro);
        }
        return DP[index][buy]= profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>DP(n+1, vector<int>(2 , -1));
        int profit = solve(prices, 0, 1, DP, fee);
        
        return profit;
    }
};