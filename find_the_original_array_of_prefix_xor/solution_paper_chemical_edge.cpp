class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        int curr = pref[0];
        vector<int> res(n, curr);
        for(int i = 1; i < n; i++) {
            res[i] = pref[i] ^ curr;
            curr = pref[i];
        }
        return res;
    }
};