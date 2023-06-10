class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, len = s.length();
        int j = len - 1;
        int ch1 = 0, ch2 = 0;
        char temp;
        bool i1, j1;
        i1 = false; j1 = false;
        while(i <= j)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                ch1 = i;
                i1 = true;
            }
            else
                i += 1;
            
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
            {
                ch2 = j;
                j1 = true;
            }
            else
                j -= 1;
            
            if(i1 == true && j1 == true)
            {
                temp = s[ch1];
                s[ch1] = s[ch2];
                s[ch2] = temp;
                i1 = false;
                j1 = false;
                i += 1;
                j -= 1;
            }
        }
        return s;
    }
};