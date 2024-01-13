class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size() == 0) {
            sort(right.begin(), right.end());
            return n - right[0];
        }
        if (right.size() == 0) {
            sort(left.begin(), left.end());
            return left[left.size() - 1];
        }

        vector<int> left_inv;
        for(int i = 0; i < left.size(); i++)
            left_inv.push_back(n - left[i]);
            
        sort(left_inv.begin(), left_inv.end());
        sort(right.begin(), right.end());
        int max_time = n - min(left_inv[0], right[0]);
        return max_time;
    }
};