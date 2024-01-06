#pragma GCC optimize("03", "unroll-loop")
class Solution {
    #define mod 1000000007
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); hFences.push_back(m);
        sort(hFences.begin(), hFences.end());
        vFences.push_back(1); vFences.push_back(n);
        sort(vFences.begin(), vFences.end());

        unordered_set<int> diff;
        int h_s = hFences.size(), v_s = vFences.size();
        long long res = -1;
        for(int i = 0; i < h_s; i++) {
            for(int j = i+1; j < h_s; j++)
                diff.insert(hFences[j] - hFences[i]);
        }
        for(int i = 0; i < v_s; i++) {
            for(int j = i+1; j < v_s; j++) {
                long long temp = vFences[j] - vFences[i];
                if(diff.find(temp) != diff.end())
                    res = max(temp, res);
            }
        }
        return res < 0 ? -1 : (res*res) % mod;
    }
};