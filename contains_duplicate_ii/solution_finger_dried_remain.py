class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        prev_pos = dict()
        pos_diff = sys.maxsize
        for i, num in enumerate(nums):
            if num in prev_pos:
                diff = abs(i - prev_pos[num])
                if diff <= pos_diff:
                    pos_diff = diff
            prev_pos[num] = i
        if pos_diff <= k:
            return True
        return False