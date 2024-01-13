class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        int i = 0, n = s.length();
        bool flag = 1;
        while(i < n) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                paren.push(s[i]);

            else if((s[i] == ')' || s[i] == ']' || s[i] == '}') && paren.empty()) {
                flag = 0;
                break;
            }
            else if(s[i] == ')' && paren.top() == '(') {
                paren.pop();
            }
            else if(s[i] == ']' && paren.top() == '[') {
                paren.pop();
            }
            else if(s[i] == '}' && paren.top() == '{') {
                paren.pop();
            }
            else {
                flag = 0;
                break;
            }
            i += 1;
        }
        return paren.empty() ? flag : 0;
    }
};