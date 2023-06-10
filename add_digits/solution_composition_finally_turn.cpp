class Solution {
public:
    int addDigits(int num) {
        if(num > 9) {
            int temp = num, sum = 0;
            while(temp > 0) {
                sum += temp % 10;
                temp = temp / 10;
            }
            if(sum > 9) {
                return addDigits(sum);
            }

            else{
                return sum;
            }
        }
        else{
            return num;
        }
    }
};