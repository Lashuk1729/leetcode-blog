class Solution {
public:
    int mod = 1e9 + 7;

    long long power(long long x, long long y) {
        if(y == 0)
            return 1;
        if(y == 1)
            return x;

        long long ans = 1;
        if (y % 2 == 0) {
            ans = power(x, y / 2);
            ans *= ans;
        } 
        else {
            ans = power(x, y - 1);
            ans *= x;
        }
        return ans % mod;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int high = nums.size() - 1, low = 0, count = 0;
        while(low <= high) {
            if(nums[low] + nums[high] <= target) {
                count += power(2, high - low);
                count = count % mod;
                low += 1;
            }
            else{
                high -= 1;
            }
        } 
        return count % mod;
    }
};