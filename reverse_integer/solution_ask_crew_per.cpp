class Solution {
public:
    int reverse(int x) {
        int sum, rem;
        sum = 0;
        while(x)
        {
            rem = x % 10;
            if(sum > INT_MAX / 10) 
                return 0;
            
            if(sum < INT_MIN / 10) 
                return 0;
            
            sum = sum * 10 + rem;
            x = x / 10;
        }
        if(sum > INT_MAX) 
            return 0;
        
        if(sum < INT_MIN)
            return 0;
        return sum;
    }
};