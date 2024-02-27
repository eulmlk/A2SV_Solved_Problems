# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        i = 0
        answer = -1

        def traverse(node):
            nonlocal i, answer
            if not node or i >= k:
                return
            
            traverse(node.left)

            i += 1
            if i == k:
                answer = node.val

            traverse(node.right)
        
        traverse(root)
        return answer