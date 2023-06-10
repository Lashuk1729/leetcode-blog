class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        row = len(grid)
        col = len(grid[0])
        res = []
        
        for i in range(col): # for iterating through columns
            # current column
            curr_col = i 
            for j in range(row):
                # current row
                curr_row = j 
                
                # next column = current column + value in the current column(which is element 1 or -1)
                next_col = curr_col + grid[curr_row][curr_col]
                
                if next_col < 0 or next_col >= col or grid[curr_row][curr_col] ^ grid[curr_row][next_col]:
                    curr_col = -1
                    break
                    
                curr_col = next_col
            
            res.append(curr_col)

        return res