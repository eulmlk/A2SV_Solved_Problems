# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-10000)
        cur = head

        while cur:
            pos = dummy
            prev = None

            while pos and pos.val < cur.val:
                prev = pos
                pos = pos.next
            
            prev.next = ListNode(cur.val, pos)
            cur = cur.next
        
        return dummy.next