class Solution:
    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)  # Number of rows
        n = len(grid[0])  # Number of columns

        # Initialize the answer matrix
        answer = [[0] * n for _ in range(m)]

        # Calculate the top-left diagonals
        topLeft = [[set() for _ in range(n)] for _ in range(m)]
        for r in range(m):
            for c in range(n):
                i, j = r-1, c-1
                while i >= 0 and j >= 0:
                    topLeft[r][c].add(grid[i][j])
                    i -= 1
                    j -= 1

        # Calculate the bottom-right diagonals
        bottomRight = [[set() for _ in range(n)] for _ in range(m)]
        for r in range(m):
            for c in range(n):
                i, j = r+1, c+1
                while i < m and j < n:
                    bottomRight[r][c].add(grid[i][j])
                    i += 1
                    j += 1

        # Calculate the answer matrix
        for r in range(m):
            for c in range(n):
                answer[r][c] = abs(len(topLeft[r][c]) - len(bottomRight[r][c]))

        return answer