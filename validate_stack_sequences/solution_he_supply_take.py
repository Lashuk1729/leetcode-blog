class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack_res = []
        i = 0
        j = 0
        while j < len(popped):
            if len(stack_res) != 0:
                if stack_res[-1] == popped[j]:
                    stack_res.pop()
                    j += 1
                    continue
            
                else:
                    if i == len(pushed):
                        return False
            
            if i < len(pushed):
                stack_res.append(pushed[i])
                i += 1

        return True