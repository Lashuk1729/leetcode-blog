class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low, high, mid, pos;
        low = 0;
        high = nums.size() - 1;
        while(low <= high){
            mid = low + ((high - low) / 2);
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] < target)
            {
                low = mid + 1;
                high = high;
            }
            else if(nums[mid] > target)
            {
                low = low;
                high = mid - 1;
            }
        }
        if(target > nums[mid])
            return mid + 1;
        else
            return mid;
    }
};