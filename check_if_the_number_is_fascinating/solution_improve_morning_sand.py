class Solution:
    def isFascinating(self, n: int) -> bool:
        num1 = 2 * n
        num2 = 3 * n
        if len(str(num1)) > 3:
          return False
        if len(str(num2)) > 3:
          return False
        res_num = str(n) + str(num1) + str(num2)
        res_set = set()
        for ch in res_num:
          if ch != '0':
            res_set.add(ch)
          
        return len(res_set) == 9