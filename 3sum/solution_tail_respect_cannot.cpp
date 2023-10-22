class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> unique_vec;
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                if(target == nums[i] + nums[j] + nums[k]) {
                    unique_vec.insert({nums[i], nums[j], nums[k]});
                    j++; k--;
                }
                else if(target < nums[i] + nums[j] + nums[k])
                    k--;

                else
                    j++;
            }
        }
        vector<vector<int>> res;
        for(auto iter: unique_vec)
            res.push_back(iter);

        return res;
    }
};