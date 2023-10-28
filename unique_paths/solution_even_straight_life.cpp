class Solution {
public:
    int nCr(int n,int r) {
        long long res=1;
        r = min(r, n-r);
        for(int i = 1;i <= r; i++) {
            res*= (n - i + 1);
            res/= i;
        }
        return res;
    }
    int uniquePaths(int m,int n) {
        return nCr(m + n - 2, m - 1);
    }
};