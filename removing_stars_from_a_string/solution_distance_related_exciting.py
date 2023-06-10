class Solution:
    def removeStars(self, s: str) -> str:
        res_s = ""
        i = 0
        for ch in s:
            if ch != "*":
                res_s += ch
                i += 1

            else:
                res_s = res_s[:-1]

        return res_s