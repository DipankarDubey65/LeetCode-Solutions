# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode | None, left: int, right: int) -> ListNode | None:
        before = None
        pos = 1
        t = head

        while pos < left:
            before = t
            t = t.next
            pos += 1

        curr = t
        prev = None
        times = right - left + 1

        while times:
            ne = curr.next
            curr.next = prev
            prev = curr
            curr = ne
            times -= 1

        if before is None:
            head = prev
        else:
            before.next = prev

        t.next = curr

        return head