# pragma GCC optimize("O3", "unroll-loop")

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank[0].size(), n = bank.size();
        if(n == 1)
            return 0;
        vector<int> count_row;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                count += bank[i][j] - '0';
            }
            if(count > 0)
                count_row.push_back(count);
        }
        if(count_row.size() > 1) {
            int res = 0, row = count_row.size();
            for(int i = 1; i < row; i++) {
                res += count_row[i-1] * count_row[i];
            }
            return res;
        }
        else
            return 0;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();