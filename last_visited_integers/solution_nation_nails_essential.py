class Solution:
    def lastVisitedIntegers(self, words: List[str]) -> List[int]:
        stack = []
        visit = []
        res = []
        i = 0
        count = 1
        
        for num in words:
            if num != "prev":
                stack.append(int(num))
                count = 1
                
            else:
                if len(stack) >= count:
                    res.append(stack[-count])
                    count += 1
                else:
                    res.append(-1)
                    
        return res
        
        
            
                
            
                
            
                