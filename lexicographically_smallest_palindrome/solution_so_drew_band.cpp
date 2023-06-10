class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int low = 0, high = s.length() - 1;
        while(low <= high) {
            if(s[low] != s[high]) {
                if(s[low] - s[high] < 0)
                    s[high] = s[low];
                else
                    s[low] = s[high];
            }
            low += 1;
            high -= 1;
        }
        return s;
    }
};