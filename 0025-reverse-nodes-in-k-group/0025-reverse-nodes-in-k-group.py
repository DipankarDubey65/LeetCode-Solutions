# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse_func(self, head, k):
        curr = head
        prev = None

        while k > 0:
            nex = curr.next
            curr.next = prev
            prev = curr
            curr = nex
            k -= 1
    def reverseKGroup(self, head: ListNode | None, k: int) -> ListNode | None:
        if head is None:
            return head

        left = head
        res = None
        prevleft = None

        while True:
            right = left

            for i in range(k - 1):
                if right is None:
                    break
                right = right.next

            if right is not None:
                nextleft = right.next

                self.reverse_func(left, k)

                if prevleft is not None:
                    prevleft.next = right

                prevleft = left

                if res is None:
                    res = right

                left = nextleft

            else:
                if prevleft is not None:
                    prevleft.next = left

                if res is None:
                    res = left

                break

        return res 