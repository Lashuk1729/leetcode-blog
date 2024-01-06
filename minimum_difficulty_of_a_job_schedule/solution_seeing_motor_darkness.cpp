# pragma GCC optimize("03", "unroll-loop")

class Solution {
public:
    int minDiffJobRecur(vector<int>& jobDifficulty, int index, int d, int& n, vector<vector<int>>& dp) {
        if(dp[index][d] != -1)
            return dp[index][d];
            
        if(d == 1) {
            int max_n = INT_MIN;
            for(int i = index; i < n; i++)
                max_n = max(max_n, jobDifficulty[i]);
            return dp[index][d] = max_n;
        }
    
        int max_n = jobDifficulty[index];
        int ans = INT_MAX;
        for(int i = index+1; i <= n - d + 1; i++) {
            ans = min(ans, max_n + minDiffJobRecur(jobDifficulty, i, d-1, n, dp));
            max_n = max(max_n, jobDifficulty[i]);
        }
        return dp[index][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n)
            return -1;

        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        return minDiffJobRecur(jobDifficulty, 0, d, n, dp);
    }
};