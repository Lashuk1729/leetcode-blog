class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vowels;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vowels.push(s[i]);
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                vowels.push(s[i]);
        }
        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = vowels.top();
                vowels.pop();
            }
        }
        return s;
    }
};