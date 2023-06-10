class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0, num = nums[0];
        for(int i = 0; i < k; i++) {
            sum += num + i;
        }
        return sum;
    }
};