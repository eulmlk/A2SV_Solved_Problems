# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def symm(node1, node2):
            if not node1 and node2 or node1 and not node2:
                return False
            
            if not node1 and not node2:
                return True
            
            if node1.val != node2.val:
                return False
            
            if not symm(node1.left, node2.right):
                return False
            
            return symm(node1.right, node2.left)
        
        return symm(root, root)