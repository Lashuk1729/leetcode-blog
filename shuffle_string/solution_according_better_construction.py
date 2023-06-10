class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        dict_str = dict()
        ret_str = ''
        for i in range(len(indices)):
            dict_str[indices[i]] = s[i]
        for i in range(len(indices)):
            ret_str += dict_str[i]
        return ret_str