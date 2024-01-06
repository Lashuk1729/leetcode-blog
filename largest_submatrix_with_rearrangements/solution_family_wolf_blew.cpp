class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int> each_col(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0)
                    each_col[j] = 0;

                each_col[j] += matrix[i][j];
            }

            vector<int> sort_col = each_col;
            sort(sort_col.begin(), sort_col.end());
            for(int j = 0; j < m; j++)
                ans = max(ans, sort_col[j] * (m - j));
        }
        return ans;
    }
};