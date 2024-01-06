class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> one_row(m, 0), zero_row(m, 0), one_col(n, 0), zero_col(n, 0);
        vector<vector<int>> diff(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    one_row[i] += 1;
                    one_col[j] += 1;
                }
                else if(grid[i][j] == 0){
                    zero_row[i] += 1;
                    zero_col[j] += 1;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                diff[i][j] = (one_row[i] + one_col[j]) - (zero_row[i] + zero_col[j]);
        }
        return diff;
    }
};