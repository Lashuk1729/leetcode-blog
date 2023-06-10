class Solution:
    def removeTrailingZeros(self, num: str) -> str:
        n = len(num)
        count = 0
        for i in range(n-1, 0, -1):
            if num[i] == '0':
                count += 1
            else:
                break
        
        return num[:-count] if count != 0 else num