class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        intersect_nums = dict()
        for num in nums1:
            if num in intersect_nums:
                intersect_nums[num] += 1
            else:
                intersect_nums[num] = 1
        
        ans_list = list()
        for num in nums2:
            if num in intersect_nums:
                intersect_nums[num] -= 1
                if intersect_nums[num] >= 0:
                    ans_list.append(num)

        return ans_list