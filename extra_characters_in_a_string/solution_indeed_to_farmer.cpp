class Solution {
public:
    int check_string_solve(string &s, unordered_map<string, int>& umap, vector<int>& dp, int iter) {
        int s_len = s.length();
        if(iter >= s_len)
            return 0;

        if (dp[iter] != -1)
            return dp[iter];
        
        string curr_str = "";
        int min_extra = s_len;

        for(int curr_i = iter; curr_i < s_len; curr_i++) {
            curr_str += s[curr_i];
            int curr_extra = umap.count(curr_str) ? 0 : curr_str.size();
            int next_extra = check_string_solve(s, umap, dp, curr_i + 1);

            min_extra = min(min_extra, curr_extra + next_extra);
        }

        return dp[iter] = min_extra;
    }
    int minExtraChar(string s, vector<string>& dict) {
        // make unordered map
        unordered_map<string, int> umap;
        for(int i = 0; i < dict.size(); i++)
            umap[dict[i]]++;

        vector<int> dp(s.length(), -1);
        return check_string_solve(s, umap, dp, 0);
            
    }
};