# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        prev = None
        maxStreak, curStreak = -1, 0

        def traverse(node):
            nonlocal result, prev, maxStreak, curStreak
            if not node:
                return
            
            traverse(node.left)

            if prev and node.val == prev.val:
                curStreak += 1
            else:
                curStreak = 0
            
            if curStreak > maxStreak:
                result = [node.val]
                maxStreak = curStreak
            elif curStreak == maxStreak:
                result.append(node.val)
                
            prev = node
        
            traverse(node.right)

        traverse(root)
        return result
