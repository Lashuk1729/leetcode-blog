# pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int count = 0, n = nums.size();
        vector<int> res(1, nums[0]);
        for(int i = 0; i < n; i++) {
            if(nums[i] > res.back())
                res.push_back(nums[i]);

            else {
                int left = 0, right = res.size() - 1;
                while(left < right) {
                    int mid = left + (right - left)/2;
                    if(res[mid] >= nums[i])
                        right = mid;

                    else
                        left = mid + 1;
                }
                res[left] = nums[i];
            }
        }
        return res.size();
    }
};