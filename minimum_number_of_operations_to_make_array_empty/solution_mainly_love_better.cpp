# pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq_count;
        for(int i = 0; i < n; i++)
            freq_count[nums[i]] += 1;
        bool flag = 1;
        int ans = 0;
        for(auto i: freq_count) {
            if(i.second == 1) {
                flag = 0;
                break;
            }
            ans += i.second / 3;
            if(i.second % 3)
                ans += 1;
        }
        return flag ? ans : -1;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();