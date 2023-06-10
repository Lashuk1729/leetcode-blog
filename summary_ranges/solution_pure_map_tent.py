class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        count = 0
        str_list = []
        for i in range(1, len(nums) + 1):
            if i < len(nums):
                if nums[i] == nums[i-1] + 1:
                    count += 1
                
                else:
                    if count != 0:
                        str_list.append(str(nums[i-1] - count) +"->"+str(nums[i-1]))
                        count = 0
                    else:
                        str_list.append(str(nums[i-1]))
                        count = 0
            else:
                if count != 0:
                    str_list.append(str(nums[i-1] - count) +"->"+str(nums[i-1]))
                    count = 0
                else:
                    str_list.append(str(nums[i-1]))
                    count = 0
        return str_list