class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size() - 1] != 9)
            digits[digits.size() - 1] += 1;
        else
        {
            bool flag = false;
            for(int i = digits.size() - 1; i >=0; i--)
            {
                if(digits[i] == 9)
                    digits[i] = 0;
                else
                {
                    flag = true;
                    digits[i] += 1;
                    break;
                }
            }
            if(flag != true)
                digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};