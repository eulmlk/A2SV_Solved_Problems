# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n = 0
        cur = head
        while cur:
            cur = cur.next
            n += 1
        
        amount = n // k
        extras = n % k

        result = []
        cur = head
        while cur:
            curSize = amount
            if extras:
                curSize += 1
                extras -= 1
            
            newHead = cur
            prev = None
            for _ in range(curSize):
                prev = cur
                cur = cur.next
            
            if prev:
                prev.next = None
            result.append(newHead)
        
        while len(result) < k:
            result.append(None)
        
        return result