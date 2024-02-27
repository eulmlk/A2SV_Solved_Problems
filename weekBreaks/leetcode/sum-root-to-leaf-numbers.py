# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        total = 0
        cur = []

        def getNums(node):
            nonlocal total, cur
            if not node:
                return
            
            if not node.left and not node.right:
                val = 0

                for num in cur:
                    val *= 10
                    val += num
                
                val *= 10
                val += node.val
                total += val
                
                
            cur.append(node.val)
            getNums(node.left)
            getNums(node.right)
            cur.pop()
        
        getNums(root)
        return total