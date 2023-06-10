class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        num_set = set(range(0, len(nums)+1))
        for num in nums:
            if num in num_set:
                num_set.remove(num)
        return num_set.pop()