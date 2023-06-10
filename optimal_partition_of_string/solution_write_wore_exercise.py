class Solution:
    def partitionString(self, s: str) -> int:
        opt_part = 1
        sub_s = ''
        for ch in s:
            if ch in sub_s:
                opt_part += 1
                sub_s = str(ch)
            sub_s = sub_s + ch

        return opt_part
            