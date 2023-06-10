class Solution {
public:
    bool isPerfectSquare(int num) {
        return sqrt(num*1.0) == floor(sqrt(num*1.0));
    }
};