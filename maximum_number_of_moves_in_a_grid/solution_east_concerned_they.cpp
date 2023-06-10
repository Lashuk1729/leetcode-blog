class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 1;
        int m = grid.size(), n = grid[0].size();
        if (j == n-1) {
            // last column
        } else {
            if (i > 0 && grid[i-1][j+1] > grid[i][j]) {
                ans = max(ans, dfs(i-1, j+1, grid, dp)+1);
            }
            if (grid[i][j+1] > grid[i][j]) {
                ans = max(ans, dfs(i, j+1, grid, dp)+1);
            }
            if (i < m-1 && grid[i+1][j+1] > grid[i][j]) {
                ans = max(ans, dfs(i+1, j+1, grid, dp)+1);
            }
        }

        dp[i][j] = ans;
        return ans;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, dfs(i, 0, grid, dp));
        }
        return ans-1;
    }
};