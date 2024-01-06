# pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        bool ans = 0;
        int count = 0;
        const int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0)
                count += 1;
            if(count >= 2) {
                ans = 1;
                break;
            }
        }
        return ans;
    }
};