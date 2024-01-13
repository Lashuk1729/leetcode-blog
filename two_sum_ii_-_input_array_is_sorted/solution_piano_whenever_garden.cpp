class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int temp_tar = target - nums[i];
            int left = i+1, right = n-1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(nums[mid] == temp_tar)
                    return {i+1, mid+1};
                else if(nums[mid] > temp_tar)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return {};
    }
};