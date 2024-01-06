class Solution {
public:
    # define mod9 1000000007
    int reverseNumber(int num) {
        int sum = 0;
        while(num > 0) {
            int rem = num % 10;
            sum = sum*10 + rem;
            num = num / 10;
        }
        return sum;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> rev_nums;
        for(int i = 0; i < n; i++) {
            rev_nums.push_back(reverseNumber(nums[i]));
        }

        int ans = 0;
        unordered_map<int, int> freq_count;
        for(int i = 0; i < n; i++) {
            int freq = nums[i] - rev_nums[i];
            freq_count[freq] += 1;
            ans = (ans % mod9) + ((freq_count[freq] - 1) % mod9); 
        }
        return ans % mod9;
    }
};