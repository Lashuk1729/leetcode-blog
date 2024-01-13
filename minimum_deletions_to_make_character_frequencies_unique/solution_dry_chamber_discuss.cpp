class Solution {
public:
    int minDeletions(string s) {
        vector<int> alpha_dict(26, 0);
        set<int> freq;
        for(int i = 0; i < s.size(); i++) {
            alpha_dict[s[i] - 97] += 1;
        }
        int count = 0;
        for(int i = 0; i < 26; i++) {
            while(alpha_dict[i] > 0 && freq.find(alpha_dict[i]) != freq.end()) {
                count += 1;
                alpha_dict[i] -= 1;
            }
            freq.insert(alpha_dict[i]);
        }
        return count;
    }
};