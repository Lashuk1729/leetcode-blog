# pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    int dp[50005];
    int solve(int i, vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int n)
    {
        if(i==n-1)
            return profit[n-1];
        
        if(i>n-1)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int pos = lower_bound(startTime.begin()+i+1, startTime.end(), endTime[i])-startTime.begin();
        
        return dp[i]=max(profit[i]+solve(pos, startTime, endTime, profit, n), solve(i+1, startTime, endTime, profit, n));
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> vec(profit.size());
        for(int i=0; i<profit.size(); i++)
        {
            vec[i].push_back(startTime[i]);
            vec[i].push_back(endTime[i]);
            vec[i].push_back(profit[i]);
        }
        
        sort(vec.begin(), vec.end());
        
        for(int i=0; i<profit.size(); i++)
        {
            startTime[i] = vec[i][0];
            endTime[i] = vec[i][1];
            profit[i] = vec[i][2];
        }
        
        memset(dp, -1, sizeof(dp));
        
        return solve(0, startTime, endTime, profit, profit.size());
    }
};