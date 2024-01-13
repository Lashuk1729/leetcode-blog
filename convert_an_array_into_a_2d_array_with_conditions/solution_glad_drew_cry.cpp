# pragma GCC optimize("O3", "unroll-loop")

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> num_freq;
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++) {
            num_freq[nums[i]] += 1;
            count = max(count, num_freq[nums[i]]);
        }
        vector<vector<int>> res(count);
        for(auto num: num_freq) {
            int n = num.first;
            int freq = num.second;
            for(int i = 0; i < freq; i++)
                res[i].push_back(n);
        }
        return res;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
