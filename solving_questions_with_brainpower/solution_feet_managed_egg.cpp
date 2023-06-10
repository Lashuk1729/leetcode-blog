class Solution {
public:
    long long pointsScored(vector<vector<int>>& questions, int n, vector<long long>& dp) {
        if(n >= questions.size())
            return 0;
        
        else {
            if(dp[n] != -1)
                return dp[n];
            
            else {
                return dp[n] = max(pointsScored(questions, n+1, dp), questions[n][0] + pointsScored(questions, n + questions[n][1] + 1, dp));
            }
        }
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return pointsScored(questions, 0, dp);
    }
};