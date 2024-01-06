class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int max_len = 0, left = 0;
        unordered_map<char, int> uniqCharPos;

        for(int right = 0; right < n; right++) {
            if(uniqCharPos.count(s[right]) == 0 || uniqCharPos[s[right]] < left) {
                uniqCharPos[s[right]] = right;
                max_len = max(max_len, right - left + 1);
            }
            else {
                left = uniqCharPos[s[right]] + 1;
                uniqCharPos[s[right]] = right;
            }
        }
        return max_len;
    }
};