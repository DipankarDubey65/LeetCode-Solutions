class Solution:
    def findMin(self, nums: list[int]) -> int:
        n = len(nums)
        s = 0
        e = len(nums) - 1
        ans = -1

        while s <= e:
            mid = s + (e - s) // 2

            if nums[mid] > nums[n - 1]:
                s = mid + 1

            else:
                ans = nums[mid]
                e = mid - 1

        return ans