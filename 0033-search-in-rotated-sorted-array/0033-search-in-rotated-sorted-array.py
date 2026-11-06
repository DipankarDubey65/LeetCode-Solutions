class Solution:
    def search(self, nums: list[int], target: int) -> int:
        n = len(nums)
        s = 0
        e = n - 1
        edge = -1

        # Find edge point (minimum element index)
        while s <= e:
            mid = s + (e - s) // 2

            if nums[mid] > nums[n - 1]:
                s = mid + 1
            else:
                edge = mid
                e = mid - 1

        # Search in first sorted half
        s1 = 0
        e1 = edge - 1

        while s1 <= e1:
            mid = s1 + (e1 - s1) // 2

            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                e1 = mid - 1
            else:
                s1 = mid + 1

        # Search in second sorted half
        s2 = edge
        e2 = n - 1

        while s2 <= e2:
            mid = s2 + (e2 - s2) // 2

            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                e2 = mid - 1
            else:
                s2 = mid + 1

        return -1
