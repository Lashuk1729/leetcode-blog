class Solution {
public:
    int hammingWeight(uint32_t n) {
        int rem = 0, sum = 0;
        while(n){
            rem = n % 2;
            sum += rem;
            n = n / 2;
        }
        return sum;
    }
};