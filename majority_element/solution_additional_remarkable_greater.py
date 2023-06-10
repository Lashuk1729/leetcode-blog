class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num_dict = dict()
        for num in nums:
            if num in num_dict:
                num_dict[num] += 1
            else:
                num_dict[num] = 1
                
        value_sort = sorted(num_dict.items(), key=lambda item: item[1], reverse=True)
        return value_sort[0][0]