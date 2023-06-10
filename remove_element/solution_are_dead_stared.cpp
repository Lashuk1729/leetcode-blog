class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0, len = nums.size();
        for(int i = 0; i < nums.size();)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                count += 1;
            }
            else
                i += 1;
        }
        return nums.size();
    }
};