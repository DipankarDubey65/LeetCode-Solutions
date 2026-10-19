class Solution:
    def maximumSum(self, arr: list[int]) -> int:
        n = len(arr)
        power = 0
        nopower = arr[0]
        res = arr[0]

        for i in range(1, n):
            v1 = arr[i]
            v2 = nopower + arr[i]
            v3 = power + arr[i]
            v4 = nopower

            res = max(res, max(max(v1, v2), max(v3, v4)))

            nopower = max(v1, v2)
            power = max(v3, v4)

        return res