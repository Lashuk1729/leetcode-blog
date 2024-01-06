class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min_steps = n;
        
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int right = 0;
        for (int left = 0; left < nums.size(); left++) {
            while (right < nums.size() && nums[right] < nums[left] + n) {
                right++;
            }
            min_steps = min(min_steps, n - (right - left));
        }
        return min_steps;  
    }
};