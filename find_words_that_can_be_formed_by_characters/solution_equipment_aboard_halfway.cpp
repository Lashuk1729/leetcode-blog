class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> freq_count;
        int res = 0, n = chars.length();
        for(int i = 0; i < n; i++)
            freq_count[chars[i]] += 1;

        n = words.size();
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> temp_count = freq_count;
            bool flag = 1;
            int len = words[i].length();
            for(int j = 0; j < len; j++) {
                if(temp_count[words[i][j]] > 0)
                    temp_count[words[i][j]] -= 1;
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                res += words[i].size();
        }
        return res;
    }
};