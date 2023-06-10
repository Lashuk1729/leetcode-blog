class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0, len = columnTitle.length();
        for(int i = 0; i <= len - 1; i++)
            sum = sum * 26 + (columnTitle[i] - 64);
        return sum;
    }
};