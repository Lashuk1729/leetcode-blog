class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos_min = 0, pos_max = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[pos_max])
                pos_max = i;
            if(nums[i] < nums[pos_min])
                pos_min = i;
        }
        if(pos_min == 0 && pos_max == n - 1)
            return 0;
        
        if(pos_min < pos_max)
            return pos_min + (n - 1 - pos_max);
        
        return pos_min + (n - 1 - pos_max) - 1;
    }
};