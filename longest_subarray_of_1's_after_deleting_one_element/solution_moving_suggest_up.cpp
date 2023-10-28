class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> position_z;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0)
                position_z.push_back(i);
        }

        if(position_z.size() == 1 || position_z.size() == 0)
            return n - 1;

        if(nums[n-1] != 0)
            position_z.push_back(n);

        int len1 = 0, len2 = 0, max_len = 0;
        for(int i = 1; i < position_z.size(); i++) {
            if(i == 1)
                len1 = position_z[i-1];
            else
                len1 = len2;

            len2 = position_z[i] - position_z[i-1] - 1;
            if(max_len < len1 + len2)
                max_len = len1 + len2; 
        }
        return max_len;
    }
};