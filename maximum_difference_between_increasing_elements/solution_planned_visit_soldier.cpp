class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int num_now, max_diff, curr_diff;
        num_now = INT_MAX;
        max_diff = -1;
        curr_diff = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(num_now > nums[i])
                num_now = nums[i];
            curr_diff = nums[i] - num_now;
            if(curr_diff - 1 > max_diff)
                max_diff = curr_diff;
        }
        return max_diff;
    }
};