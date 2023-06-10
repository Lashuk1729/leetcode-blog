class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        set<int> left, right;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++) {
                left.insert(nums[j]);
            }

            for (int j = i + 1; j < n; j++) {
                right.insert(nums[j]);
            }
            
            res.push_back((int)left.size() - (int)right.size());
            left.clear();
            right.clear();
        }
        return res;
    }
};