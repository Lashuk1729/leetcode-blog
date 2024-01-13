class Solution {
public:
    string reverse(string s) {
        int n = s.length();
        string res = "";
        for(int i = n-1; i >= 0; i--) {
            res += s[i];
        }
        return res;
    }
    string reverseWords(string s) {
        string res = "", temp = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] != ' ')
                temp += s[i];

            else {
                res += reverse(temp) + " ";
                temp = "";
            }
        }
        res += reverse(temp);
        return res;
    }
};