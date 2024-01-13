class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        priority_queue<int> max_sum;
        
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            max_sum.push(nums[left] + nums[right]);
            left += 1;
            right -= 1;
        }
        return max_sum.top();
    }
};