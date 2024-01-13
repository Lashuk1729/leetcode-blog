# pragma GCC optimize("O3", "unroll-loop")

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank[0].size(), n = bank.size();
        if(n == 1)
            return 0;
        
        int res = 0, prev = 0;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                count += bank[i][j] - '0';
            }
            if(count > 0) {
                res += prev * count;
                prev = count;
            }
        }
        return res;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();