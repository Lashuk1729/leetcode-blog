class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_ind;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums_ind.push_back(make_pair(nums[i], i));
        }
        sort(nums_ind.begin(), nums_ind.end());
        for(int i = 0; i < n-1; i++) {
            int remain = target - nums_ind[i].first;
            int left = i+1, right = n-1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(nums_ind[mid].first == remain)
                    return {nums_ind[i].second, nums_ind[mid].second};
                else if(nums_ind[mid].first > remain)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return {};

    }
};