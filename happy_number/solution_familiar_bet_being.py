class Solution:
    def isHappy(self, n: int) -> bool:
        sum_set = set()
        while True:
            r_sum = 0
            while n:
                rem = n % 10
                r_sum += rem ** 2
                n = n // 10
                
            if r_sum == 1:
                return True
            
            if r_sum in sum_set:
                return False
            else:
                sum_set.add(r_sum)
                
            n = r_sum