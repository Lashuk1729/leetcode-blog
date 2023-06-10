class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        ran_note = dict()
        for char in ransomNote:
            if char in ran_note:
                ran_note[char] += 1
            else:
                ran_note[char] = 1
                
        for char in magazine:
            if char in ran_note:
                if ran_note[char] > 0:
                    ran_note[char] -= 1
            
        for char, val in ran_note.items():
            if val != 0:
                return False

        return True