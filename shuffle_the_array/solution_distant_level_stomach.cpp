class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res_num;
        for(int i = 0; i < n; i++){
            res_num.push_back(nums[i]);
            res_num.push_back(nums[n+i]);
        }
        return res_num;
    }
};