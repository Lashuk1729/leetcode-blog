class Solution {
public:
    int indexBinSearch(vector<int>& nums, int target, bool flag) {
        int left = 0, right = nums.size() - 1;
        int return_in = -1;
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            if(nums[mid] == target)
            {
                return_in = mid;
                if(flag == 0)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return return_in;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int one = indexBinSearch(nums, target, 0);
        int two = indexBinSearch(nums, target, 1);
        return {one, two};
    }
};