class Solution {
public:
    bool check_indices(int index, int k) {
        int total_rem = 0;
        while(index > 0) {
            total_rem += index % 2;
            index = index / 2;
        }
        if(total_rem == k)
            return true;
        else
            return false;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(check_indices(i, k))
                sum += nums[i];
        }
        return sum;
    }
};