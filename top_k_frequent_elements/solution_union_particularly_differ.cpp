class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto compare = [](pair<int, int> low, pair<int, int> high){return low.second > high.second;};
        unordered_map<int, int> freq_count;
        for(auto iter: nums)
            freq_count[iter] += 1;

        vector<int> res;
        vector<pair<int, int>> freq_item(freq_count.begin(), freq_count.end());
        sort(freq_item.begin(), freq_item.end(), compare);
        for(auto iter: freq_item) {
            if(k)
                res.push_back(iter.first);
            else
                break;
            k -= 1;
        }
        return res;
    }
};