class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1)
            return true;

        int n = s.length();
        vector<int> str_num;
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z')
                str_num.push_back(s[i] - 'A');

            else if(s[i] >= 'a' && s[i] <= 'z')
                str_num.push_back(s[i] - 'a');

            else if(s[i] >= '0' && s[i] <= '9')
                str_num.push_back(s[i] - 'a');
        }

        int left = 0, right = str_num.size() - 1;
        while(left < right) {
            if(str_num[left] != str_num[right])
                return false;
            left += 1;
            right -= 1;
        }
        return true;
    }
};