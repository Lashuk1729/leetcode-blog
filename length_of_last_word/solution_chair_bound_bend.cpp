class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_len = 0, len = s.length() - 1;
        bool flag = false;
        for(int i = len; i >= 0; i--)
        {
            if(flag == false)
            {
                if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                {
                    flag = true;
                    last_len += 1;
                }
            }
            else
            {
                if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '-'))
                {
                    flag = true;
                    last_len += 1;
                }
                else if(s[i] == ' ')
                    break;
            }
        }
        return last_len;
    }
};