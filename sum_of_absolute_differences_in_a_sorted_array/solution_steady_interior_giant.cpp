class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        vector<int> prefix_sum;
        for(int i = 0; i < n; i++) {
            if(i == 0)
                prefix_sum.push_back(nums[0]);
            else
                prefix_sum.push_back(prefix_sum[i-1] + nums[i]);
        }
        for(int i = 0; i < n; i++) {
            int left_sum = i*nums[i] - (i > 0 ? prefix_sum[i-1] : 0);
            int right_sum = (prefix_sum[n-1] - prefix_sum[i]) - (n-1-i)*nums[i];
            nums[i] = left_sum + right_sum;
        }
        return nums;
    }
};