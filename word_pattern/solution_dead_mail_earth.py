class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s_list = s.split(' ')
        pat_dict = dict()
        
        if len(pattern) != len(s_list): 
            return False
        
        if len(set(pattern)) != len(set(s_list)): 
            return False
        
        for i, char in enumerate(pattern):
            if char in pat_dict:
                if s_list[i] != pat_dict[char]:
                    return False
            else:
                pat_dict[char] = s_list[i]
        
        return True