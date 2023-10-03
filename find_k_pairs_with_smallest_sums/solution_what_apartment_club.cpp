class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        
        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < min(k, static_cast<int>(nums1.size())); ++i) {
            pq.push({i, 0});
        }
        
        while (k-- > 0 && !pq.empty()) {
            auto idx = pq.top();
            pq.pop();
            res.push_back({nums1[idx.first], nums2[idx.second]}); 

            if (idx.second + 1 < nums2.size()) {
                pq.push({idx.first, idx.second + 1});
            }
        }
        
        return res;
    }
};