# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        vals = []

        def traverse(node):
            if not node:
                return
            
            traverse(node.left)
            vals.append(node.val)
            traverse(node.right)
        
        traverse(root)

        counts = Counter(vals)
        maxCount = max(counts.values())

        result = []
        for num, count in counts.items():
            if count == maxCount:
                result.append(num)
        
        return result
