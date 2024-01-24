# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        seek, hold = head, head

        while seek:
            while seek and seek.val == hold.val:
                seek = seek.next
            
            hold.next = seek
            hold = hold.next
        
        return head