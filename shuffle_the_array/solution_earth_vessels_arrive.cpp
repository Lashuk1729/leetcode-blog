class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res_num(2*n);
        int k = 0;
        for(int i = 0; i < n; i++){
            res_num[k] = nums[i];
            res_num[k+1] = nums[n+i];
            k += 2;
        }
        return res_num;
    }
};