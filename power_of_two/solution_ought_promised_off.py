class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1:
            return True
        num = 1
        while n:
            temp = n
            n = n - pow(2, num)
            if n > 0:
                n = temp
                num += 1
            elif n == 0:
                return True
            else:
                return False