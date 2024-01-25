# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        left, right = head, head
        for _ in range(n):
            right = right.next
        
        prev = None
        while right:
            prev = left
            left = left.next
            right = right.next
        
        if prev:
            prev.next = prev.next.next
            return head
        else:
            return head.next