class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0, len = columnTitle.length();
        for(int i = 0; i <= len - 1; i++)
        {
            sum += (columnTitle[i] - 64) * pow(26, len - i - 1);
        }
        return sum;
    }
};