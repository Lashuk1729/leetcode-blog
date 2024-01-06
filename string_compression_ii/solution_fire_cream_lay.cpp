# pragma GCC optimize("03", "unroll-loop")
class Solution {
public:
    int removeCharStringRecur(int index, char prev, int currCharFreq, string &s, int k, int n, int dp[][27][11][101]) {
        if(k < 0) 
            return 1e9;
        
        if(index >= n)
            return 0;

        if(currCharFreq >= 10)
            currCharFreq = 10;

        if(dp[index][prev - 'a'][currCharFreq][k] != -1)
            return dp[index][prev - 'a'][currCharFreq][k];

        /*
        Four Cases:
        1. Remove the current character if k > 0, this wll make our string minimum;
        2. If our current character != previous character, ans is increased by 1 and
           currCharFreq will also be 1.
        3. If our current character == previous character
            3.1. If it is either 1 or more than 9, ans is increased by 1.
            3.2. Else, we just increase currCharFreq.
        */

        int ans = 1e9;
        ans = min(ans, removeCharStringRecur(index + 1, prev, currCharFreq, s, k-1, n, dp));

        if(s[index] != prev)
            ans = min(ans, 1 + removeCharStringRecur(index + 1, s[index], 1, s, k, n, dp));

        else {
            if(currCharFreq == 1 || currCharFreq == 9) {
                ans = min(ans, 1 + removeCharStringRecur(index + 1, prev, currCharFreq + 1, s, k, n, dp));
            }
            else{
                ans = min(ans, removeCharStringRecur(index + 1, prev, currCharFreq + 1, s, k, n, dp));
            }
        }
        return dp[index][prev - 'a'][currCharFreq][k] = ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        if(n == k)
            return 0;
        // all characters same?
        bool flag = 1;
        for(int i = 0; i < n-1; i++) {
            if(s[i] != s[i+1]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            n -= k;
            if(n == 1)
                return 1;
            return log10(n) + 1 + 1;
        }

        int dp[n+1][27][11][101];
        memset(dp, -1, sizeof(dp));
        return removeCharStringRecur(0, 'z', 0, s, k, n, dp);
    }
};