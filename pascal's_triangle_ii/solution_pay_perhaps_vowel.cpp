class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal_mat(rowIndex+1);
        for(int i = 0; i < rowIndex+1; i++) {
            pascal_mat[i] = vector<int> (i+1);
            pascal_mat[i][0] = 1;
        }
        for(int i = 1; i < rowIndex+1; i++){
            for(int j = 1; j <= i; j++) {
                if(j == i)
                    pascal_mat[i][j] = 1;

                else
                    pascal_mat[i][j] = pascal_mat[i-1][j] + pascal_mat[i-1][j-1];
            }
        }
        vector<int> res(pascal_mat[rowIndex].begin(), pascal_mat[rowIndex].end());
        return res;
    }
};