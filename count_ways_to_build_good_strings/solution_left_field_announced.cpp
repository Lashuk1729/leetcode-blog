class Solution {
public:
    int mod = 1e9+7;
    
    int solve(int low, int high, int zero, int one, int length, vector<int> &memo){
        if(length > high)
            return 0;

        else {
            if(memo[length] != -1)
                return memo[length];

            else {
                int sol_0 = solve(low, high, zero, one, length + zero, memo) % mod;
                int sol_1 = solve(low, high, zero, one, length + one, memo) % mod;

                int res = (sol_0 + sol_1) % mod;
                if(length >= low){
                    res++;
                }
                return memo[length] = res;
            }
        }
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int mx = max(zero , one);
        vector<int> memo(high + mx + 1 , -1);
        return solve(low, high, zero, one, 0, memo) % mod;
    }
};