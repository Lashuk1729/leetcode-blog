class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> alpha_count (26, 0);
        for(int i = 0; i < n; i++) {
            for(char ch: words[i])
                alpha_count[ch - 'a'] += 1;
        }
        for(int i = 0; i < 26; i++) {
            if(alpha_count[i] != 0 && alpha_count[i] % n != 0)
                return 0;
        }
        return 1;
    }
};