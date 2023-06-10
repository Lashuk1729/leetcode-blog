# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        if n == 1:
            return 1
        else:
            low = 1
            high = n
            ans = -1
            while low <= high:
                mid = low + (high - low) // 2
                if isBadVersion(mid) == True:
                    ans = mid
                    high = mid - 1
                else:
                    low = mid + 1
            return ans