# pragma GCC optimize("03", "unroll-loop")
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length(), ans = 0;
        for(int i = 1; i < n; i++) {
            char prev = colors[i-1], curr = colors[i];
            if(curr == prev) {
                ans += min(neededTime[i], neededTime[i-1]);
                neededTime[i] = max(neededTime[i], neededTime[i-1]);
            }
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();