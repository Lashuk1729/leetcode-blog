class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1:
            return True
        num = 1
        flag = False
        while num < n:
            flag = n >= pow(3, num)
            if flag == True:
                if n == pow(3, num):
                    return True
                else:
                    num += 1
            else:
                break
                    
        return False