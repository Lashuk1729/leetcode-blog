# pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        vector<pair<int, int>> alpha_count(26, {-1, -300});
        for(int i = 0; i < n; i++) {
            if(alpha_count[s[i] - 'a'].first == -1)
                alpha_count[s[i] - 'a'].first = i;
            else
                alpha_count[s[i] - 'a'].second = max(alpha_count[s[i] - 'a'].second, i);
        }
        int ans = -1;
        for(int i = 0; i < 26; i++)
            ans = max(ans, alpha_count[i].second - alpha_count[i].first - 1);

        return ans;
    }
};