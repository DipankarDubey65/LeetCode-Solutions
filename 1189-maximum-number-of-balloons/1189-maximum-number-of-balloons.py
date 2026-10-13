class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        have = {}
        need = {}
        res = float('inf')

        for c in text:
            have[c] = have.get(c, 0) + 1

        text2 = "balloon"

        for c in text2:
            need[c] = need.get(c, 0) + 1

        for c in need:
            times = have.get(c, 0) // need[c]
            print(times)
            res = min(res, times)

        return res