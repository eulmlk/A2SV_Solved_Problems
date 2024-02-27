# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        columns = defaultdict(dict)
        minCol, maxCol = float('inf'), float('-inf')

        def traverse(node, row, col):
            nonlocal minCol, maxCol, columns

            if not node:
                return
            
            if row in columns[col]:
                columns[col][row].append(node.val)
            else:
                columns[col][row] = [node.val]
            
            minCol = min(minCol, col)
            maxCol = max(maxCol, col)

            traverse(node.left, row + 1, col - 1)
            traverse(node.right, row + 1, col + 1)
        
        traverse(root, 0, 0)
        
        result = []
        for col in range(minCol, maxCol + 1):
            minRow = min(columns[col].keys())
            maxRow = max(columns[col].keys())
            column = []

            for row in range(minRow, maxRow + 1):
                if row in columns[col]:
                    columns[col][row].sort()
                    column.extend(columns[col][row])
            
            result.append(column)
        
        return result