class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_index;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            nums_index.push_back(make_pair(nums[i], i));

        sort(nums_index.begin(), nums_index.end());
        for(int i = 0; i < n; i++) {
            int req = target - nums_index[i].first;
            int left = i+1, right = n-1;
            while(left <= right) {
                int mid = left + ((right - left) / 2);
                if(nums_index[mid].first == req) {
                    res.push_back(nums_index[i].second);
                    res.push_back(nums_index[mid].second);
                    return res;
                }

                else if(nums_index[mid].first < req) {
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
        }
        return res;
    }
};