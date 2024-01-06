class Solution {
public:
    int maxScore(string s) {
        int countOne = 0, countZero = 0, n = s.length(), maxSum = INT_MIN;
        for(int i = 0; i < n; i++)
            countOne += (s[i] == '1') ? 1 : 0;

        for(int i = 0; i < n-1; i++) {
            countZero += (s[i] == '0') ? 1 : 0;
            countOne -= (s[i] == '1') ? 1 : 0;
            maxSum = max(maxSum, countZero + countOne);
        }
        return maxSum;
    }
};