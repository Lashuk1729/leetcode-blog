#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int minOperations(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0 && s[i] == '1')
                res += 1;
            if(i % 2 == 1 && s[i] == '0')
                res += 1;
        }
        return min(res, n - res);
    }
};