class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(seen[nums[i]] >= 1)
                return true;
            seen[nums[i]] += 1;
        }
        return false;
    }
};