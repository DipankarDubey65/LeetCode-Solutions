class Solution:
    def peakIndexInMountainArray(self, arr: list[int]) -> int:
        s = 0
        e = len(arr) - 1
        ans = 0

        while s <= e:
            mid = s + (e - s) // 2

            if arr[mid] < arr[mid + 1]:
                s = mid + 1
            else:
                ans = mid
                e = mid - 1

        return ans