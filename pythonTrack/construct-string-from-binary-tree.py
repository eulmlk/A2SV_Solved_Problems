# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        
        def getStr(node):
            if not node:
                return ''
            
            if not node.left and not node.right:
                return f'{node.val}'
            
            if not node.right:
                return f'{node.val}({getStr(node.left)})'

            return f'{node.val}({getStr(node.left)})({getStr(node.right)})'
        
        return getStr(root)