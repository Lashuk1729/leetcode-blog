class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        max_n = 0
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1,n):
                    if ((nums[i] - nums[j]) * nums[k]) > max_n:
                        max_n = (nums[i] - nums[j]) * nums[k]
        return max_n
                        