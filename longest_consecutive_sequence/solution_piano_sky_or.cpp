class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> freq_nums;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            freq_nums[nums[i]] += 1;
        }
        bool flag = 0;
        int count = 0, res = INT_MIN, prev;
        for(auto i = freq_nums.begin(); i != freq_nums.end(); i++) {
            if(flag == 0) {
                count = 1;
                prev = i->first;
                flag = 1;
            }

            else {
                if(i->first == prev+1) {
                    count += 1;
                    prev = i->first;
                }
                else if(i->second > 1 || i->first != prev+1){
                    res = max(count, res);
                    count = 1;
                    prev = i->first;
                }
            }
        }
        return max(count, res);
    }
};