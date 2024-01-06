class Solution {
public:
    int rob_house(vector<int>& nums, int i, int n, vector<int>& dp) {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = nums[i] + max(rob_house(nums, i+2, n, dp), rob_house(nums, i+3, n, dp));
        
        return dp[i];
        
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans1 = rob_house(nums, 0, nums.size(), dp);
        int ans2 = rob_house(nums, 1, nums.size(), dp);
        return max(ans1, ans2);
    }
};