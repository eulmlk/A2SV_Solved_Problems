# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        rev = None
        fast, slow = head, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        head1 = head
        head2 = None

        while slow:
            temp = slow.next
            slow.next = head2
            head2 = slow
            slow = temp
        
        while head1 and head2:
            if head1.val != head2.val:
                return False
            
            head1 = head1.next
            head2 = head2.next
        
        return True