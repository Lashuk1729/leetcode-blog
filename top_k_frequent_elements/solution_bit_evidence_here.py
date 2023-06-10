class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        unique_element = {}
        for num in nums:
            if num in unique_element:
                unique_element[num] += 1
            else:
                unique_element[num] = 1

        unique_element = dict(sorted(unique_element.items(), key=lambda item: item[1], reverse=True))

        res = []
        num = 0
        for key in unique_element:
            res.append(key)
            num += 1
            if num == k:
                break
        
        return res