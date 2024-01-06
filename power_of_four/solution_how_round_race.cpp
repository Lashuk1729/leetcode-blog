class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
        else {
            while(n > 1) {
                int rem = n % 4;
                if(rem > 0)
                    return false;
                n = n / 4;
            }
            return true;
        }
    }
};