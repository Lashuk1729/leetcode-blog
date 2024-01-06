class Solution {
public:
    int remain_one(int n) {
        int ones = 0;
        while(n > 0) {
            if(n % 2 == 1)
                ones += 1;
            n /= 2;
        }
        return ones;
    }

    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i = 1; i <= n; i++) {
            res[i] = remain_one(i);
        }
        return res;
    }
};