class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        for(i = 0; i < s.length();)
        {
            for(j = 0; j < t.length(); j++)
            {
                if(t[j] == s[i])
                {
                    i+=1;
                }
            }
            if(j == t.length() and i != s.length())
                return false;
            else
                return true;
        }
        return true;
    }
};