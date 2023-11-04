class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        long long totalSum = 0;
        for(int i = 0; i < n; i++)
            totalSum += nums[i];

        if(target > totalSum){
            count = (target / totalSum)*n;
            target = target % totalSum;
        }

        int left = 0, right = 0, min_res = INT_MAX;
        long long sum = 0;
        bool iff = false;

        while(right < 2*n) {
            sum += nums[right % n];

            while(sum > target && left <= right) {
                sum -= nums[left % n];
                left += 1;
            }

            if(sum == target) {
                iff = true;
                min_res = min(min_res, right - left + 1);
            }

            right += 1;
        }
        return iff ? min_res + count : -1;
    }
};