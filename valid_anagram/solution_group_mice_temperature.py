class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        total_letter_freq = dict()
        for char in s:
            if char in total_letter_freq:
                total_letter_freq[char] += 1
            else:
                total_letter_freq[char] = 1
                
        for char in t:
            if char in total_letter_freq:
                if total_letter_freq[char] < 0:
                    return False
                else:
                    total_letter_freq[char] -= 1
            else:
                return False
        
        for _, val in total_letter_freq.items():
            if val > 0:
                return False
            
        return True