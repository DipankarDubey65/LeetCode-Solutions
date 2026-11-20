class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])

        l = 0
        h = n - 1
        row = 0

        # Binary search to find the correct row
        while l <= h:
            mid = l + (h - l) // 2

            if matrix[mid][0] <= target:
                row = mid
                l = mid + 1
            else:
                h = mid - 1

        # Binary search inside the selected row
        s = 0
        e = m - 1

        while s <= e:
            mid = s + (e - s) // 2

            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] < target:
                s = mid + 1
            else:
                e = mid - 1

        return False