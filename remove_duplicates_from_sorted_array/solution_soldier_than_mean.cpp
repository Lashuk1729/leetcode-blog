class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int count = 1;
        for(int i = 1; i < len; i++)
        {
            if(nums[i] != nums[count - 1])
            {
                nums[count] = nums[i];
                count += 1;
            }
        }
        return count;
    }
};