class Solution:
    def getWordsInLongestSubsequence(self, n: int, words: List[str], groups: List[int]) -> List[str]:
        alter_bin = []
        alter_bin.append(0)
        for i in range(1, len(groups)):
            if groups[alter_bin[-1]] != groups[i]:
                alter_bin.append(i)
        
        res = []
        for i in alter_bin:
            res.append(words[i])
        return res