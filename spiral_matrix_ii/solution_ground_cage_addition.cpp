class Solution {
public:
    void print(vector<vector<int>> & mat) {
        int n = mat.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << mat[i][j] <<" ";
            cout << endl;
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n , vector<int> (n, 0));
        int row_low = 0, col_low = 0, row_high = n-1, col_high = n-1;
        int count = 1;
        int i = row_low, j = col_low;

        while(count <= n*n) {
            // left to right
            for(j = col_low; j <= col_high; j++) {
                mat[row_low][j] = count;
                count += 1;
            }

            // up to down
            for(i = row_low + 1; i <= row_high; i++) {
                mat[i][col_high] = count;
                count += 1;
            }

            if(row_low >= row_high && col_low >= col_high)
                break;

            // right to left
            for(j = col_high - 1; j >= col_low; j--) {
                mat[row_high][j] = count;
                count += 1;
            }

            // down to up
            for(i = row_high - 1; i > row_low; i--) {
                mat[i][col_low] = count;
                count += 1;
            }

            row_low += 1;
            row_high -= 1;
            col_low += 1;
            col_high -= 1;
        }
        return mat;
    }
};