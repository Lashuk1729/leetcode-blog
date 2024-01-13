class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int curr = nums[left] + nums[right];
            if(curr == target)
                return {left+1, right+1};
            else if(curr > target)
                right -= 1;
            else
                left += 1;
        }
        return {};
    }
};