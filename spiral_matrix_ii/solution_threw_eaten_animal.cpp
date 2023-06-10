class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n, vector<int> (n));
        int low_i = 0, low_j = 0, high_i = n-1, high_j = n-1;
        int start = 1;
        while(low_i <= high_i && low_j <= high_j)
        {
            // left to right
            for(int j = low_j; j < high_j; j++)
            {
                spiral[low_i][j] = start;
                start += 1;
            }
            // up to down
            for(int i = low_i; i <= high_i; i++)
            {
                spiral[i][high_j] = start;
                start += 1;
            }
            // for moving right to left
            if(low_j <= high_j)
            {
                for(int j = high_j -1; j >= low_j; j--)
                {
                    spiral[high_i][j] = start;
                    start += 1;
                }
            }
            // for moving up
            if(low_i <= high_i)
            {
                for(int i = high_i - 1; i > low_i; i--)
                {
                    spiral[i][low_j] = start;
                    start += 1;
                }
            }
            low_i += 1;
            high_i -= 1;
            low_j += 1;
            high_j -= 1;
        }
        return spiral;
    }
};