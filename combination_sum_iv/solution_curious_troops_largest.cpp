class Solution {
public: 
    int total_distinct_comb(int target, vector<int>& nums, vector<unsigned int>& dp) {
        if(target == 0)
            return 1;
        else if(target < 0)
            return 0;
        
        if(dp[target] != -1)
            return dp[target];

        int actual_ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            actual_ans += total_distinct_comb(target - nums[i], nums, dp);
        }
        return dp[target] = actual_ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, -1);
        return total_distinct_comb(target, nums, dp);
    }
};