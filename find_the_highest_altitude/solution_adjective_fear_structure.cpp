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
        return *max_element(cummul_sum.begin(), cummul_sum.end());
    }
};