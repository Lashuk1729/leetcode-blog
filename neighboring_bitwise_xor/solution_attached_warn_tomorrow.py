class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        n = len(derived)
        xor_derived = 0
        for i in range(n):
            xor_derived ^= derived[i]
        original_first = derived[n-1] ^ xor_derived
        original = [0] * n
        original[0] = original_first
        for i in range(1, n):
            original[i] = derived[i-1] ^ original[i-1]
        
        print(original)
        return derived == [original[i] ^ original[(i+1)%n] for i in range(n)]