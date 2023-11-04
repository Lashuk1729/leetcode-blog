class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force Solution
        vector<int> twoSumIndex;
        bool flag = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] + nums[j] == target)
                {
                    flag = 1;
                    twoSumIndex.push_back(j);
                    twoSumIndex.push_back(i);
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        return twoSumIndex;
    }
};