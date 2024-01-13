class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> posSum_nums;
        vector<int> res;
        int max_pos = 0, n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            int in_n = nums[i].size();
            for(int j = 0; j < in_n; j++) {
                posSum_nums[i+j].push_back(nums[i][j]);
                if(max_pos < i + j)
                    max_pos = i + j;
            }
        }
        for(int i = 0; i <= max_pos; i++) {
            for(auto iter: posSum_nums[i]) {
                res.push_back(iter);
            }
        }
        return res;
    }
};