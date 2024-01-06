class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1, n = arr.size(), ind = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1]) {
                if(count > n/4) {
                    ind = i-1;
                    break;
                }
                count = 1;
            }
            else {
                count += 1;
            }
            ind = i;
        }
        return arr[ind];
    }
};