# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if right - left < 1:
            return head
        
        nodeLeft, nodeRight = head, head

        for _ in range(right - left):
            nodeRight = nodeRight.next
        
        prev = None
        for _ in range(left - 1):
            prev = nodeLeft
            nodeLeft = nodeLeft.next
            nodeRight = nodeRight.next
        
        cur = nodeLeft
        rev = nodeRight.next
        while cur != nodeRight.next:
            newNode = ListNode(cur.val, rev)
            rev = newNode
            cur = cur.next
        
        if prev:
            prev.next = rev
            return head
        else:
            return rev
        
