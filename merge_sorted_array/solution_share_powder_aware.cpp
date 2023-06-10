class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = m + n - 1;
        if(m == 0)
            nums1 = nums2;
        
        else
        {
            if(n != 0)
            {
                int i, j;
                i = m - 1;
                j = n - 1;
                while(i >= 0 && j >= 0)
                {
                    if(nums1[i] >= nums2[j])
                    {
                        nums1[count] = nums1[i];
                        nums1[i] = 0;
                        i -= 1;
                        count -= 1;
                    }
                    else
                    {
                        nums1[count] = nums2[j];
                        j -= 1;
                        count -= 1;
                    }
                }
                while(i >= 0)
                {
                    nums1[count] = nums1[i];
                    count -= 1;
                    i -= 1;
                }
                while(j >= 0)
                {
                    nums1[count] = nums2[j];
                    count -= 1;
                    j -= 1;
                }
            }
        }
    }
};