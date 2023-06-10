class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        pascal_lst = [[1]*(i+1) for i in range(rowIndex+1)]
        for i in range(1, rowIndex+1):
            for j in range(1, i):
                pascal_lst[i][j] = pascal_lst[i-1][j-1] + pascal_lst[i-1][j]

        return pascal_lst[rowIndex]