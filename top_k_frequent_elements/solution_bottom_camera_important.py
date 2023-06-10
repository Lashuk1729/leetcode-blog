class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_dict = dict()
        for num in nums:
            if num in freq_dict:
                freq_dict[num] += 1
            else:
                freq_dict[num] = 1
        freq_dict = sorted(freq_dict.items(), reverse=True, key=lambda item: item[1])
        return [freq_dict[i][0] for i in range(k)]