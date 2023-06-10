class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int i = 0; i < index.size(); i++)
        {
            int num = nums[i];
            int pos = index[i];
            res.insert(res.begin() + pos, num);
        }
        return res;
    }
};