# pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child_size = g.size() - 1, cookie_size = s.size() - 1;
        if(cookie_size == -1 || child_size == -1)
            return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        for(int j = 0; count <= child_size && j <= cookie_size; j++)
            if(g[count] <= s[j])
                count += 1;
        return count;
    }
};