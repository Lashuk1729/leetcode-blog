class Solution {

public:
    int binarySearch(vector<int>& nums, int low, int high, int target){
        if (high - low < 0) 
            return 0;
        
        if (high - low == 0) 
        {
            if (target <= nums[low]) 
            {
                return low;
            } 
            else 
            {
                return low + 1;
            }
        }
        
        if (high - low == 1) 
        {
            if (target <= nums[low]) 
            {
                return low;
            } 
            else if (target > nums[high]) 
            {
                return low + 2;
            } 
            else 
            {
                return low + 1;
            }
        }
        
        int mid = low + ((high - low  + 1) / 2);
        if(nums[mid] == target)
            return mid;

        else if(nums[mid] < target)
            return binarySearch(nums, mid+1, high, target);

        else
            return binarySearch(nums, low, mid-1, target);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int low, high, pos;
        low = 0;
        high = nums.size() - 1;
        
        pos = binarySearch(nums, low, high, target);
        return pos;
    }
};