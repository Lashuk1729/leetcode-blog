class Solution:
    def countBits(self, n: int) -> List[int]:
        bin_list = list()
        for i in range(n+1):
            count = 0
            while i >= 1:
                rem = i % 2
                i = i // 2
                count += rem
            bin_list.append(count)
        return bin_list