class Solution {
public:
    string convertToTitle(int columnNumber) {
        int rem, quo;
        string res = "";
        while(columnNumber)
        {
            rem = (columnNumber - 1) % 26;
            res = char(rem + 65) + res;
            columnNumber = (columnNumber - 1) / 26;
        }
        return res;
    }
};