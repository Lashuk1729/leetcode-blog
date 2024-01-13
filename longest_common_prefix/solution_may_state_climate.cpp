class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int common_len = prefix.length();
        for(int i = 1; i < strs.size(); i++) {
            int j = 0;
            for(j = 0; j < common_len; j++) {
                if(strs[i][j] != prefix[j])
                    break;
            }
            common_len = j;
        }
        prefix.resize(common_len);
        return prefix;
    }
};