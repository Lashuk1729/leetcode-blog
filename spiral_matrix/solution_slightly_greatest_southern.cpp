class Solution {
public:
    void print(vector<int>& res) {
        for(int i = 0; i < res.size(); i++)
            cout << res[i] <<",";
        cout << endl;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int lowRow = 0, highRow = m - 1;
        int lowCol = 0, highCol = n - 1;
        int i, j;
        vector<int>ans;
        while(lowRow <= highRow && lowCol <= highCol)
        {
            //===================================================================
            //TOP-LEFT to TOP-RIGHT
            i = lowRow; j = lowCol;
            while(j <= highCol)
            {
                ans.push_back(matrix[i][j]);
                j++;
            }
            lowRow++; //increment the lowRow, we will not use it now
            //===================================================================
            //TOP-RIGHT to BOTTOM-RIGHT
            j = highCol; i = lowRow;
            while(i <= highRow)
            {
                ans.push_back(matrix[i][j]);
                i++;
            }
            highCol--; //decrement the highCol, we will not use it now
            //====================================================================
            //BOTTOM-RIGHT to BOTTOM-LEFT
            //WE COULD EVEN VANISH THE MATRIX IN MIDWAY
            if (lowRow > highRow || lowCol > highCol) break;  //***IMPORTANT*****
            i = highRow; j = highCol;
            while(j >= lowCol)
            {
                ans.push_back(matrix[i][j]);
                j--;
            }
            highRow--; //decrement the highRow, we will not use it now
            //=====================================================================
            //BOTTOM-LEFT to TOP-LEFT
            j = lowCol; i = highRow;
            while(i >= lowRow)
            {
                ans.push_back(matrix[i][j]);
                i--;
            }
            lowCol++; //decrement the lowCol, we will not use it now
            //=========================================================================
        }
        return ans;
    }
};