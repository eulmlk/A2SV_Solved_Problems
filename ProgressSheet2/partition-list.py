# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        dummy1 = ListNode()
        dummy2 = ListNode()

        below, above = dummy1, dummy2

        while head:
            if head.val < x:
                below.next = ListNode(head.val)
                below = below.next
            else:
                above.next = ListNode(head.val)
                above = above.next

            head = head.next
        
        below.next = dummy2.next
        return dummy1.next