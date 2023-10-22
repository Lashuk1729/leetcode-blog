class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<long long> sum_nums;
        sum_nums.push_back(0);
        
        bool flag = false;
        int n = nums.size(), min_len = INT_MAX;
        
        for(int i = 1; i <= n; i++) {
            if(nums[i-1] >= target){
                flag = true;
                break;
            }
            sum_nums.push_back(nums[i-1] + sum_nums[i-1]);
        }
        if(flag == true)
            return 1;
        
        if(sum_nums[n] == target)
            return n;

        for(int i = 0; i < n; i++) {
            int left = i+1, right = n;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                int sum = sum_nums[mid] - sum_nums[i];

                if(sum >= target) {
                    min_len = min(min_len, mid - i);
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            
        }
        if(min_len == INT_MAX)
            return 0;
        else
            return min_len;
    }
};