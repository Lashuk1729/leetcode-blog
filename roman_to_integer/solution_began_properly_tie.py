class Solution:
    def romanToInt(self, s: str) -> int:
        roman_dict = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        prev_num = roman_dict[s[0]]
        num = roman_dict[s[0]]
        for i in range(1, len(s)):
            if s[i] in roman_dict:
                prev_num = roman_dict[s[i-1]]
                if prev_num < roman_dict[s[i]]:
                    num += roman_dict[s[i]] - 2*prev_num
                else:
                    num += roman_dict[s[i]]

        return num