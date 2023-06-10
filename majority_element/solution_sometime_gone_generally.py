class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num_dict = dict()
        for num in nums:
            if num in num_dict:
                num_dict[num] += 1
            else:
                num_dict[num] = 1
            
        max_val = -1
        for key, value in num_dict.items():
            if value > max_val:
                max_val = value
                max_key = key
                
        return max_key