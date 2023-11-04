class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int max_len = 0, cur_len = 0;
        int n = nums.size();
        if(n == 1)
        {
            if(nums[0] % 2 == 0 && nums[0] <= threshold)
                return 1;
            else
                return 0;
        }
        for(int l = 0; l < n; l++) {
            if(nums[l] % 2 == 0 && nums[l] <= threshold) {
                cur_len = 1;
                for(int r = l+1; r < n; r++) {
                    if(nums[r] % 2 != nums[r-1] % 2 && nums[r] <= threshold)
                        cur_len += 1;
                    else
                        break;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};