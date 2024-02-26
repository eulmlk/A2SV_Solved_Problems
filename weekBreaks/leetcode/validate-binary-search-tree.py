# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def isValid(node, maxVal, minVal):
            if not node:
                return True

            if node.val >= maxVal or node.val <= minVal:
                return False
            
            return isValid(node.left, node.val, minVal) and \
                    isValid(node.right, maxVal, node.val)
        
        return isValid(root, float('inf'), float('-inf'))