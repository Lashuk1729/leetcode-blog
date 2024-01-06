class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> freq_count;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            freq_count[nums[i]] += 1;

        priority_queue<pair<int, int>> sort_key_freq;
        for(auto iter: freq_count)
            sort_key_freq.push({iter.first, iter.second});

        long long count = 0;
        while(sort_key_freq.size() > 1) {
            auto it = sort_key_freq.top();
            sort_key_freq.pop();
            count += it.second;
            auto itr = sort_key_freq.top();
            sort_key_freq.pop();
            sort_key_freq.push({itr.first, it.second+itr.second});
        }
        return static_cast<int>(count);
    }
};