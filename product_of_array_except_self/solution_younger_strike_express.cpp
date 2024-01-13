class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int, int> prod_num;
        int zero = 0, prod = 1, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0){
                zero += 1;
                continue;
            }
            prod = prod * nums[i];
        }
        vector<int> res(n, 0);
        if(zero == 1) {
            for(int i = 0; i < n; i++) {
                if(nums[i] == 0)
                    res[i] = prod;
                else
                    res[i] = 0;
            }
        }
        else if(zero == 0) {
            for(int i = 0; i < n; i++) {
                res[i] = prod / nums[i];
            }
        }
        return res;
    }
};