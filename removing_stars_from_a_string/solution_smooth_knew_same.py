class Solution:
    def removeStars(self, s: str) -> str:
        res_s = list()
        for ch in s:
            if ch == "*":
                res_s.pop()
                continue
            res_s.append(ch)
        return "".join(res_s)