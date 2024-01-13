class Solution {
public:
    int mod = 1e9+7;
    long long dp[10][5002];
    vector<vector<int>> knightPhone = {{4,6}, {8,6}, {7,9}, {8,4}, {3,9,0}, {}, {1,7,0}, {6,2}, {1,3}, {2,4}};

    long long dfs(int ind, int n){
        if(n == 0) 
            return 1;

        if(dp[ind][n] != -1) 
            return dp[ind][n];

        long long res = 0;
        for(auto iter : knightPhone[ind]){
            res += dfs(iter, n-1);
            res = res % mod;
        }
        return dp[ind][n] = res % mod;
    }
    int knightDialer(int n) {
        if(n == 1) 
            return 10;
        
        memset(dp, -1, sizeof(dp));

        long long res = 0;
        for(int i = 0; i < 10; i++){
            if(i == 5) 
                continue;
            res += dfs(i, n - 1) % mod;
            res = res % mod;
        }
        return res % mod;
    }
};