class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1 = 0, element2 = 0;
        int count1 = 0, count2 = 0;
        int n = nums.size();

        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(nums[i] == element1)
                count1 += 1;
            else if(nums[i] == element2)
                count2 += 1;
            else if(count1 == 0) {
                count1 = 1;
                element1 = nums[i];
            }
            else if(count2 == 0) {
                count2 = 1;
                element2 = nums[i];
            }
            else {
                count1 -= 1;
                count2 -= 1;
            }
        }
        count1 = 0; count2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == element1)
                count1 += 1;
            else if(nums[i] == element2)
                count2 += 1;
        }

        if(count1 > n / 3)
            res.push_back(element1);
        if(count2 > n / 3)
            res.push_back(element2);

        return res;
    }
};