class Solution {
public:
    int climbStairs(int n) {
        int num1 = 1, num2 = 2, num3;
        if(n == 1)
            return num1;
        else if(n == 2)
            return num2;
        else
        {
            for(int i=3; i<=n; i++)
            {
                num3 = num1 + num2;
                num1 = num2;
                num2 = num3;
            }
            return num3;
        }
    }
};