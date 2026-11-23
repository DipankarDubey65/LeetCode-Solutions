class Solution:
    def ansCalculate(self, matrix, k, guess):
        n = len(matrix)
        m = len(matrix[0])

        r = n - 1
        c = 0
        count = 0

        while r >= 0 and c < m:
            if matrix[r][c] > guess:
                r -= 1
            else:
                count += r + 1
                c += 1

        return count

    def kthSmallest(self, matrix: list[list[int]], k: int) -> int:
        n = len(matrix) - 1
        m = len(matrix[0]) - 1

        res = -1

        l = matrix[0][0]
        h = matrix[n][m]

        while l <= h:
            guess = l + (h - l) // 2

            ans = self.ansCalculate(matrix, k, guess)

            if ans < k:
                l = guess + 1
            else:
                res = guess
                h = guess - 1

        return res