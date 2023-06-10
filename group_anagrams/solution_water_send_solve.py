class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = {}
        for s in strs:
            sorted_str = "".join(sorted(s))
            
            if sorted_str not in ans:
                ans[sorted_str] = []
                
            ans[sorted_str].append(s)

        return list(ans.values())
            
        