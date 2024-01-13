class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s_nums1(nums1.begin(), nums1.end()), s_nums2(nums2.begin(), nums2.end()), common;

        for (int x: s_nums1) {
            if (s_nums2.find(x) != s_nums2.end()) {
                common.insert(x);
            }
        }
        int n = nums1.size(), n1 = s_nums1.size(), n2 = s_nums2.size(), c = common.size();
        return min(n, min(n1 - c, n / 2) + min(n2 - c, n / 2) + c);

    }
};