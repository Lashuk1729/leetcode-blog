class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int tracker = nums[0];
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count == 0)
                tracker = nums[i];
            
            if(tracker == nums[i])
                count += 1;
            else
                count -= 1;
        }
        return tracker;
    }
};