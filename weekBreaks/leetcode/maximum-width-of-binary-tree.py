# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        leftMost = []
        rightMost = []

        def traverse(node, depth, col):
            if not node:
                return
            
            if len(leftMost) == depth:
                leftMost.append(col)
            else:
                leftMost[depth] = min(leftMost[depth], col)
            
            if len(rightMost) == depth:
                rightMost.append(col)
            else:
                rightMost[depth] = max(rightMost[depth], col)
            
            traverse(node.left, depth + 1, 2 * col)
            traverse(node.right, depth + 1, 2 * col + 1)
        
        traverse(root, 0, 0)
        width = -1
        
        for left, right in zip(leftMost, rightMost):
            width = max(width, right - left + 1)
        
        return width