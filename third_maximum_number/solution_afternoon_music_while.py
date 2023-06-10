class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums_lis = list(set(nums))
        nums_lis = sorted(nums_lis, reverse=True)
        if len(nums_lis) < 3:
            return nums_lis[0]
        else:
            return nums_lis[2]