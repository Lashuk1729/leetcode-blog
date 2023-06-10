class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid, low = 0, high = nums.size() - 1;
        if (target > nums[high])
            return nums.size();

        while(low <= high)
        {
            mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            if(target < nums[mid])     
                high = mid - 1;    
            else
                low = mid + 1;
        }
        return low;  
    }
};