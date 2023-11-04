class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre_sum;
        pre_sum.push_back(nums[0]);
        for(int i = 1; i < n; i++)
            pre_sum.push_back(nums[i] + pre_sum[i-1]);
        
        vector<int> k_radius;
        for(int i = 0; i < n; i++) {
            if(i - k < 0 || i + k > n - 1)
                k_radius.push_back(-1);

            else{
                long long wind = 2*k + 1;
                long long sum = pre_sum[i + k];
                if(i - k - 1 >= 0)
                    sum = sum - pre_sum[i - k - 1];

                k_radius.push_back(sum/wind);
            }
        }
        return k_radius;
    }
};