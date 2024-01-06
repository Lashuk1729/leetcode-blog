class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr_max = arr[0], win = 0, n = arr.size();
        for(int i = 1; i < n; i++) {
            if(arr[i] > curr_max) {
                curr_max = arr[i];
                win = 1;
            }
            else
                win += 1;
            if(win == k)
                break;
        }
        return curr_max;
    }
};