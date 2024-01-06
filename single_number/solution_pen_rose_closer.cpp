class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umaps;
        for(int i = 0; i < nums.size(); i++)
        {
            umaps[nums[i]]++;
        }
        unordered_map<int, int>::iterator itr;
        int res;
        for (itr = umaps.begin(); itr != umaps.end(); itr++) {
            if(itr->second == 1) {
                res = itr->first;
                break;
            }
        }
        return res;
    }
};