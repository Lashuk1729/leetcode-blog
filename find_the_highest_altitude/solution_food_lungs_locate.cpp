class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> cummul_sum;
        cummul_sum.push_back(0);
        int j = 0;
        for(int i = 0; i < gain.size(); i++){
            cummul_sum.push_back(cummul_sum[j] + gain[i]);
            j += 1;
        }
        int max_h = cummul_sum[0];
        for(int i = 1; i <= j; i++) {
            if(max_h < cummul_sum[i])
                max_h = cummul_sum[i];
        }
        return max_h;
    }
};