# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        forward = True
        queue = Deque([root])
        result = []

        while queue:
            siz = len(queue)
            row = []
            
            for _ in range(siz):
                node = queue.popleft()
                row.append(node.val)

                if node.left:
                    queue.append(node.left)
                
                if node.right:
                    queue.append(node.right)
            
            if forward:
                result.append(row)
            else:
                result.append(row[::-1])

            forward = not forward
        
        return result