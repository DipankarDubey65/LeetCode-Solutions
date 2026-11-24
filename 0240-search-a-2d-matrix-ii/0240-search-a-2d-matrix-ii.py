class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])

        r = n - 1
        c = 0

        while r >= 0 and c < m:
            if matrix[r][c] == target:
                return True

            elif matrix[r][c] > target:
                r -= 1

            else:
                c += 1

        return False