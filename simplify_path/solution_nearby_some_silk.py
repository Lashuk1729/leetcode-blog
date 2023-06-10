class Solution:
    def simplifyPath(self, path: str) -> str:
        dirc = path.split("/")[1:-1] if path[-1] == "/" else path.split("/")[1:]
        stack = []
        res_path = ""
        for fold in dirc:
            if fold == "..":
                if len(stack) == 0:
                    continue
                else:
                    stack.pop()
            elif fold == ".":
                continue
            elif fold == "":
                continue
            else:
                stack.append(fold)
        return "/" + "/".join(stack)