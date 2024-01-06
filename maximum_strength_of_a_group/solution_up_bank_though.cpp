class Solution {
    long long ans = -100;
public:
    void helper(vector<int> &nums, int ind, long long prod, bool took){
        if(nums.size() == ind){
            if(took)
            ans = max(ans, prod);
            return;
        }
        helper(nums, ind + 1, prod, took);
        helper(nums, ind + 1, nums[ind] * prod, true);
    }
    long long maxStrength(vector<int>& nums) {
        helper(nums, 0, 1, false);
        return ans;
    }
};