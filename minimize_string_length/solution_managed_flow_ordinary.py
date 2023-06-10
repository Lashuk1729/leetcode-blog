class Solution:
    def minimizedStringLength(self, s: str) -> int:
        unique_char = set([ch for ch in s])
        return len(unique_char)
            