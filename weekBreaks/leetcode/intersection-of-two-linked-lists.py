# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        nA, nB = 0, 0
        curA, curB = headA, headB

        while curA:
            curA = curA.next
            nA += 1
        
        while curB:
            curB = curB.next
            nB += 1
        
        curA, curB = headA, headB

        while nA < nB:
            curB = curB.next
            nB -= 1
        
        while nA > nB:
            curA = curA.next
            nA -= 1
        
        while curA and curB:
            if curA == curB:
                return curA
            
            curA = curA.next
            curB = curB.next
        
        return None