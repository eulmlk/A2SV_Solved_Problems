# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        dummy1 = ListNode()
        dummy2 = ListNode()

        odd = dummy1
        even = dummy2

        cur = head
        while cur and cur.next:
            odd.next = ListNode(cur.val)
            odd = odd.next
            cur = cur.next.next
        
        if cur:
            odd.next = ListNode(cur.val)
            odd = odd.next
        
        cur = head.next
        while cur and cur.next:
            even.next = ListNode(cur.val)
            even = even.next
            cur = cur.next.next
        
        if cur:
            even.next = ListNode(cur.val)
            even = even.next
        
        odd.next = dummy2.next
        return dummy1.next
