class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> c_map;
        int count = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            count += c_map[nums[i]];
            if(c_map.find(nums[i]) == c_map.end())
                c_map[nums[i]] = 1;
            else
                c_map[nums[i]] += 1;
        }
        return count;
    }
};