// # pragma GCC optimize ("O3", "unroll-loop")
class Solution {
public:
    int recurLengthLongTS(int index, int n, int prev, vector<int>& nums, vector<vector<int>> & dp) {
        if(index == n)
            return 0;
        
        if(dp[index][prev+1] != -1)
            return dp[index][prev+1];

        int len = recurLengthLongTS(index+1, n, prev, nums, dp);
        if(prev == -1 || nums[prev] < nums[index])
        {
            len = max(len, 1 + recurLengthLongTS(index+1, n, index, nums, dp));
        }
        return dp[index][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int index = 0, prev = -1; 
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return recurLengthLongTS(index, n, prev, nums, dp);
    }
};