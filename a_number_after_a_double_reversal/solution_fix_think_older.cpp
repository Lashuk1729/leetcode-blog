class Solution {
    int reverse_num(int num)
    {
        int ans = 0, count = 0;
        while(num)
        {
            ans = ans * 10 + (num % 10);
            num = num / 10;
            count += 1;
        }
        return ans;
    }
public:
    bool isSameAfterReversals(int num) {
        int reverse1 = reverse_num(reverse_num(num));
        return reverse1 ==  num;
    }
};