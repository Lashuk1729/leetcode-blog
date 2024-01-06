class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = 0;
        long long sum = 0, count = 0;
        for(right = 0; right < n; right++) {
            sum += nums[right];
            while(nums[right] * static_cast<long long>(right - left + 1) > sum + k) {
                sum -= nums[left];
                left += 1;
            }
            count = max(count, static_cast<long long>(right - left + 1));
        }
        return static_cast<int>(count);
    }
};