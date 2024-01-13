# pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0, j = 0;
        int n = g.size(), m = s.size();
        while(i < n && j < m) {
            if(g[i] <= s[j]) {
                count += 1;
                i += 1;
                j += 1;
            }
            else
                j += 1;
        }
        return count;
    }
};