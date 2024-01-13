class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int, int>> unique_pos;
        s += 'A';
        int n = s.length();
        int palin = 0;
        
        for(int i = 0; i < n-1; i++) {
            if(unique_pos[s[i]].first == 0)
                unique_pos[s[i]].first = i+1;
        }

        for(int i = n-1; i >=0; i--) {
            if(unique_pos[s[i]].second == 0 && unique_pos[s[i]].second != unique_pos[s[i]].first)
                unique_pos[s[i]].second = i+1;
        }

        for(auto iter: unique_pos) {
            if(iter.second.second != 0) {
                unordered_set<char> u_char;
                for(int i = iter.second.first; i < iter.second.second-1; i++) {
                    u_char.insert(s[i]);
                }
                palin += u_char.size();
            }
        }

        return palin;
    }
};