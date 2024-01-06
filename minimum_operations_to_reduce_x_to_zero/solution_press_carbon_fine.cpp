class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), req_sum = 0;
        for(int i = 0; i < n; i++)
            req_sum += nums[i];
        
        if(req_sum < x)
            return -1;

        req_sum -= x;

        int left = 0, right = 0, sum = 0, count = INT_MAX;
        while(right < n) {
            sum += nums[right];
            if(sum > req_sum) {
                while(left <= right && sum > req_sum) {
                    sum -= nums[left];
                    left += 1;
                }
            }
            if(sum == req_sum)
                count = min(count, n - (right - left) - 1);

            right += 1;
        }
        return count == INT_MAX ? -1 : count;
    }
};