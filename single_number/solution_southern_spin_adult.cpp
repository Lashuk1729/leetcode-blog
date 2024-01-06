class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umaps;
        for(int i = 0; i < nums.size(); i++)
        {
            if(umaps.find(nums[i]) == umaps.end())
                umaps[nums[i]] = 1;
            
            else
                umaps[nums[i]] += 1;
        }
        unordered_map<int, int>::iterator itr;
        for (itr = umaps.begin(); itr != umaps.end(); itr++) {
            if(itr->second == 1)
                return itr->first;
        }
        return 0;
    }
};