class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7, days = n % 7;
        return (week*(2*28 + (week-1)*7) / 2) + (((2*week + days + 1)*(days))/2); 
    }
};