class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums_dicts = {}
        for num in nums:
            if num in nums_dicts:
                nums_dicts[num] += 1
            else:
                nums_dicts[num] = 1
                
        for key in nums_dicts:
            if nums_dicts[key] == 1:
                return key