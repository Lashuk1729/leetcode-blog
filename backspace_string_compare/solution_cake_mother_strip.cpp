class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> new_s;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(s[i] != '#')
                new_s.push(char(s[i]));
            else {
                if(!new_s.empty())
                    new_s.pop();
            }
        }

        stack<char> new_temp;
        len = t.size();
        for(int i = 0; i < len; i++) {
            if(t[i] != '#')
                new_temp.push(char(t[i]));
            else {
                if(!new_temp.empty())
                    new_temp.pop();
            }
        }

        if(new_temp == new_s)
            return true;
        return false;
    }
};