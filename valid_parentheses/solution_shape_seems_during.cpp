class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_str;
        int len = s.length();
        for(int i = 0; i <= len; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stack_str.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(stack_str.empty() != true)
                {
                    char char_s = stack_str.top();
                    stack_str.pop();
                    if(char_s !=  '(')
                        return false;
                }
                else
                    return false;
                
            }
            else if(s[i] == ']')
            {
                if(stack_str.empty() != true)
                {
                    char char_s = stack_str.top();
                    stack_str.pop();
                    if(char_s !=  '[')
                        return false;
                }
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(stack_str.empty() != true)
                {
                    char char_s = stack_str.top();
                    stack_str.pop();
                    if(char_s !=  '{')
                        return false;
                }
                else
                    return false;
            }
        }
        if(stack_str.empty())
            return true;
        else
            return false;
    }
};