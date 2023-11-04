class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        else {
            int rem = 0;
            while(n > 1) {
                rem = n % 2;
                if(rem > 0)
                    return false;
                n = n / 2;
            }
            return true;
        }
    }
};