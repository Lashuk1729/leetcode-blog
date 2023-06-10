class Solution:
    def firstUniqChar(self, s: str) -> int:
        char_count = dict()
        for char in s:
            if char in char_count:
                char_count[char] += 1
            else:
                char_count[char] = 1
                
        i = 0
        for char, val in char_count.items():
            if val == 1:
                return s.index(char)
            i += val
        if i == len(s):
            return -1