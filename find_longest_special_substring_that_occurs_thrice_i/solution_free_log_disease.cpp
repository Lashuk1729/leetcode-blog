# pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length(), ans = -1;
        unordered_map<string, int> substr_count;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n+1; j++) {
                string ss = s.substr(i, j - i);
                set<char> st(ss.begin(), ss.end());
                if(st.size() == 1)
                    substr_count[ss] += 1;
            }
        }
        for(auto &it: substr_count) {
            if(it.second >= 3) {
                ans = max(ans, (int)it.first.length());
            }
        }
        return ans;
    }
};