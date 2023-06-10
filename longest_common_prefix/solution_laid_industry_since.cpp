class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common_pre = strs[0];
        int len = common_pre.length();
        for(int j = 1; j < strs.size(); j++)
        {
            for(int i = 0; i < len; i++)
            {
                if(common_pre[i] == strs[j][i])
                {
                    continue;
                }
                else
                {
                    len = i;
                    break;
                }
            }
        }
        common_pre = "";
        for(int i = 0; i < len; i++)
            common_pre += strs[0][i];
        return common_pre;
    }
};