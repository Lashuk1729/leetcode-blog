class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int s_len = s.size();
        int g_len = goal.size();
        if(s_len != g_len)
            return false;

        int count = 0;
        vector<int> freq(26, 0);
        bool hasDuplicates = 0;
        vector<int> needSwap;

        for(int i = 0; i < s_len; i++) {
            if (s[i] != goal[i]){
                 count += 1;
                 needSwap.push_back(i);
            }

            freq[s[i] - 'a'] += 1;
            
            if (!hasDuplicates && freq[s[i] - 'a'] >= 2) 
                hasDuplicates = true;
        }
        if (s == goal && hasDuplicates) 
            return true;

        if (s != goal && count == 2) {
            swap(s[needSwap[0]], s[needSwap[1]]);
            if (s == goal) 
                return true;
            else 
                return false;
        }
        return false;
    }
};