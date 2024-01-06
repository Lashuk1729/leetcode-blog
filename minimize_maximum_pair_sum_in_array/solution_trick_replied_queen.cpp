class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int max_sum = INT_MIN;
        while(left < right) {
            if(max_sum < nums[left] + nums[right])
                max_sum = nums[left] + nums[right];
            left += 1;
            right -= 1;
        }
        return max_sum;
    }
};