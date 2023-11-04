class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool mono = false;
        int count = 0;
        if(nums.size() == 1)
          return true;
        for(int i = 1; i < nums.size(); i++) {
          if(nums[i] <= nums[i-1])
            mono = true;
          else
          {
            mono = false;
            count = 1;
            break;
          }
        }
        if(count == 1)
        {
          for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= nums[i-1])
              mono = true;
            else
            {
              mono = false;
              break;
            }
          }
        }
        return mono;
    }
};