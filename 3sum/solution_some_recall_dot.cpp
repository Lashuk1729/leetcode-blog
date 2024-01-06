class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> res;
        sort(nums.begin(), nums.end());

        // kind of brute force using sorting => O(n^2 log n) -> does not work
        // for(int i = 0; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         int left = j+1, right = n-1;
        //         while(left <= right) {
        //             int mid = left + (right - left) / 2;
        //             if(nums[i] + nums[j] + nums[mid] == 0) {
        //                 res.insert({nums[i], nums[j], nums[mid]});
        //                 break;
        //             }
        //             else if(nums[i] + nums[j] + nums[mid] > 0)
        //                 right = mid - 1;
        //             else
        //                 left = mid + 1;
        //         }
        //     }
        // }

        for(int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                if(nums[i] + nums[left] + nums[right] == 0) {
                    res.insert({nums[i], nums[left], nums[right]});
                    left += 1;
                    right -= 1;
                }

                else if(nums[i] + nums[left] + nums[right] > 0)
                    right -= 1;
                else
                    left += 1;
            }
        }

        vector<vector<int>> ans;
        for(auto iter: res)
            ans.push_back(iter);

        return ans;
    }
};