class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowSum(m, 0);
        vector<int> colSum(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1)
                    res += 1;
            }
        }
        return res;
    }
};