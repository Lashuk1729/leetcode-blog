class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int max_1 = -1, str_len = s.length();
        for(int i = 0; i < str_len; i++)
            if(s[i] == '1')
                max_1 += 1;
        
        string res = "";
        int i = 0;
        if(max_1 > 0)
        {
            for(i = 0; i < max_1; i++)
                res += '1';   
        }
        for(i; i < str_len - 1; i++)
            res += '0';
        res += '1';
        return res;
    }
};