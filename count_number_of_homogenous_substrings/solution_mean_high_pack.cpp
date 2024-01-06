class Solution {
public:
    int countHomogenous(string s) {
        int right = 0, left = 0;
        int n = s.size();
        int res = 0, mod = 1000000007;
        for(right = 0; right < n; right++) {
            if(s[right] == s[left]) {
                res += (right - left + 1);
                res = res % mod;
            }
            else {
                left = right;
                res += 1;
                res = res % mod;
            }
        }
        return res % mod;
    }
};