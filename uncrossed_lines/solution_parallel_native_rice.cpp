class Solution {
public:
    int crossLines(vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>>&dp) {
        if(n < 0 || m < 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];

        else{
            if(nums1[n] == nums2[m])
                return 1 + crossLines(nums1, nums2, n-1, m-1, dp);

            return dp[n][m] = max(crossLines(nums1, nums2, n, m-1, dp), crossLines(nums1, nums2, n-1, m, dp));
        }
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return crossLines(nums1, nums2, n-1, m-1, dp);
        
    }
};