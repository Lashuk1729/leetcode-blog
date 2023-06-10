class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int rem = 0, i = a.length() - 1, j = b.length() - 1;
        while(i >= 0 && j >= 0)
        {
            if(rem == 0)
            {
                if(a[i] == '0' && b[j] == '0')
                    res = '0' + res;
                else if(a[i] == '1' && b[j] == '0')
                    res = '1' + res;
                else if(a[i] == '0' && b[j] == '1')
                    res = '1' + res;
                else if(a[i] == '1' && b[j] == '1')
                {
                    res = '0' + res;
                    rem = 1;
                }
            }
            else if(rem == 1)
            {
                if(a[i] == '0'  && b[j] == '0')
                {
                    res = '1' + res;
                    rem = 0;
                }
                else if(a[i] == '1' && b[j] == '0')
                {
                    res = '0' + res;
                    rem = 1;
                }
                else if(a[i] == '0' && b[j] == '1')
                {
                    res = '0' + res;
                    rem = 1;
                }
                else if(a[i] == '1' && b[j] == '1')
                {
                    res = '1' + res;
                    rem = 1;
                }
            }
            i -= 1;
            j -= 1;
        }
        while(i >= 0)
        {
            if(rem == 1)
            {
                if(a[i] == '0')
                {
                    res = '1' + res;
                    rem = 0;
                }
                else if(a[i] == '1')
                {
                    res = '0' + res;
                    rem = 1;
                }
            }
            else
            {
                res = a[i] + res;
            }
            i -= 1;
        }
        while(j >= 0)
        {
            if(rem == 1)
            {
                if(b[j] == '0')
                {
                    res = '1' + res;
                    rem = 0;
                }
                else if(b[j] == '1')
                {
                    res = '0' + res;
                    rem = 1;
                }
            }
            else
            {
                res = b[j] + res;
            }
            j -= 1;
        }
        if(rem == 1)
            res = '1' + res;
        return res;
    }
};