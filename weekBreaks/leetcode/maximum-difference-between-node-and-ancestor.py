# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def maxDiff(node, path):
            if not node:
                return float('-inf')
            
            path.append(node.val)
            maxDiffLeft = maxDiff(node.left, path)
            maxDiffRight = maxDiff(node.right, path)

            curDiff = max(node.val - min(path), max(path) - node.val)
            path.pop()
            return max(curDiff, maxDiffLeft, maxDiffRight)
        
        return maxDiff(root, [])