class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res_num;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            if(nums[i] % 2 == 0)
                res_num.push_back(nums[i]);
        for(int i = 0; i < n; i++)
            if(nums[i] % 2 == 1)
                res_num.push_back(nums[i]);

        return res_num;
    }
};