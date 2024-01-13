class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int left = 0, mid = n - 2, right = n - 1;
        int res = 0;
        while(left < mid && mid < right) {
            res += piles[mid];
            mid -= 2; right -= 2;
            left += 1;
        }
        return res;
    }
};