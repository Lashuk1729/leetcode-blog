class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_n = s.length(), t_n = t.length();
        if(s_n > t_n)
            return false;

        int count = 0;
        int i = 0, j = 0;
        while(i < s_n && j < t_n) {
            if(s[i] == t[j])
                i += 1;
            j += 1;
        }
        if(i == s_n)
            return true;
        return false;
    }
};