class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1, prev = nums[0], n = nums.size();
        vector<int> res;
        res.push_back(prev);
        for(int i = 1; i < n; i++) {
            if(prev != nums[i]) {
                prev = nums[i];
                count += 1;
                res.push_back(prev);
            }   
        }
        nums = res;
        return count;
    }
};