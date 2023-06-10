class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i, ch in enumerate(s):
            if ch == '(' or ch == '{' or ch == '[':
                stack.append(ch)

            else:
                if (ch == ')' or ch == '}' or ch == ']') and (len(stack) == 0):
                    return False
                elif ch == ")" and stack[len(stack)-1] == "(":
                    stack.pop()
                elif ch == "}" and stack[len(stack)-1] == "{":
                    stack.pop()
                elif ch == ']' and stack[len(stack)-1] == "[":
                    stack.pop()
                else:
                    return False

        if len(stack) != 0:
            return False

        else:
            return True