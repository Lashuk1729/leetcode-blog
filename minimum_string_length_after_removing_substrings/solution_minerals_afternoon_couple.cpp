class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
    
        for (char c : s) {
            // Check if the current character can form "AB" or "CD" with the last character in the stack
            if (!stk.empty() && ((stk.top() == 'A' && c == 'B') || (stk.top() == 'C' && c == 'D'))) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.size();
    }
};