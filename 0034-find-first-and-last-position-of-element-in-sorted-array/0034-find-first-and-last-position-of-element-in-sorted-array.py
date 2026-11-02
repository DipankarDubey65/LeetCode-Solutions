class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        # Find first occurrence
        s = 0
        e = len(nums) - 1
        first = -1
        last = -1

        while s <= e:
            mid = s + (e - s) // 2

            if nums[mid] == target:
                first = mid
                e = mid - 1

            elif nums[mid] < target:
                s = mid + 1

            else:
                e = mid - 1

        # Find last occurrence
        s = 0
        e = len(nums) - 1

        while s <= e:
            mid = s + (e - s) // 2

            if nums[mid] == target:
                last = mid
                s = mid + 1

            elif nums[mid] < target:
                s = mid + 1

            else:
                e = mid - 1

        return [first, last]