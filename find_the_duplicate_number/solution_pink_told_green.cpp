class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] == nums[i]) {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};