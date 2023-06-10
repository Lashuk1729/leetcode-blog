class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # Logic from Dyanmic Walk
        i = 0
        appeared = dict()
        lst1 = []
        lst2 = []
        for ch in s:
            if ch in appeared:
                lst1.append(appeared[ch])
            else:
                appeared[ch] = i;
                i += 1
                lst1.append(appeared[ch])
                
        i = 0
        appeared = dict()
        for ch in t:
            if ch in appeared:
                lst2.append(appeared[ch])
            else:
                appeared[ch] = i;
                i += 1
                lst2.append(appeared[ch])
                
        if lst1 == lst2:
            return True
        else:
            return False