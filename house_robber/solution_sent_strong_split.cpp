class Solution {
public:
    int rob_house(vector<int>& nums, int n, vector<int>& dp) {
        if(n < 0)
            return 0;

        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = nums[n] + max(rob_house(nums, n-2, dp), rob_house(nums, n-3, dp));
        
        return dp[n];
        
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans1 = rob_house(nums, nums.size()-1, dp);
        int ans2 = rob_house(nums, nums.size()-2, dp);
        return max(ans1, ans2);
    }
};