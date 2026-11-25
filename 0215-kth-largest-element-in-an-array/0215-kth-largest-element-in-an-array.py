class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        # Min heap
        pq = []

        # First k elements insert karo
        for i in range(k):
            heapq.heappush(pq, nums[i])

        # Remaining elements process karo
        for i in range(k, len(nums)):
            if nums[i] > pq[0]:
                heapq.heappop(pq)
                heapq.heappush(pq, nums[i])

        return pq[0]  