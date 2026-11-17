class Solution:
    def countTimes(self, a, n, speed):
        h = 0

        for i in range(n):
            h += a[i] // speed

            if a[i] % speed != 0:
                h += 1

        return h

    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        
        n = len(piles)

        l = 1
        high = max(piles)

        res = -1

        while l <= high:
            mid = l + (high - l) // 2

            hr = self.countTimes(piles, n, mid)

            if hr > h:
                l = mid + 1
            else:
                res = mid
                high = mid - 1

        return res
