class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal_lst = list()
        for i in range(numRows):
            lst = [1] * (i+1)
            if i == 0 or i == 1:
                pascal_lst.append(lst)
            else:
                k = 1
                up_lst = pascal_lst[i-1]
                for j in range(len(up_lst) - 1):
                    lst[k] = up_lst[j] + up_lst[j+1]
                    k += 1
                pascal_lst.append(lst)
        return pascal_lst