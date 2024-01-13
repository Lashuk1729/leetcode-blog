class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        def shiftMatrix(mat, k):
            def cyclic_shift(row, shift):
                return row[-shift:] + row[:-shift]

            m, n = len(mat), len(mat[0])

            for i in range(m):
                if i % 2 == 0:  # Even indexed row
                    mat[i] = cyclic_shift(mat[i], k % n)
                else:  # Odd indexed row
                    mat[i] = cyclic_shift(mat[i], -k % n)

            return mat

        def compareMatrices(mat1, mat2):
            return all(row1 == row2 for row1, row2 in zip(mat1, mat2))

        def checkEqualAfterShift(mat, k):
            original_mat = [row[:] for row in mat]
            shifted_mat = shiftMatrix(mat, k)
            return compareMatrices(original_mat, shifted_mat)
        
        return checkEqualAfterShift(mat, k)