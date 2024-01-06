class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> unique_nums;
        for(int i = 0; i < n; i++) {
            unique_nums[nums[i]] += 1;
        }
        for(auto i : unique_nums){
            if(i.second == 1)
                return i.first;
        }
        return 0;
    }
};