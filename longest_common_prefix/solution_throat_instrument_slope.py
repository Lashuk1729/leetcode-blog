class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common_pre = strs[0]
        for i in range(1, len(strs)):
            common_pre = common_pre[:min(len(common_pre), len(strs[i]))]
            for j in range(min(len(common_pre), len(strs[i]))):
                if common_pre[j] == strs[i][j]:
                    continue
                else:
                    common_pre = common_pre[:j]
                    break
        return common_pre