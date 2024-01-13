class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1, n = arr.size(), ind = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[ind])
                count += 1;
            else 
                count = 1;
            if(count > n/4) {
                break;
            }
            ind = i;
        }
        return arr[ind];
    }
};