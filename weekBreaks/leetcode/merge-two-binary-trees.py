# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        root = None

        def merge(node1, node2):
            if not node1 and not node2:
                return None
            
            if node1 and not node2:
                node = TreeNode(node1.val)

                node.left = merge(node1.left, node2)
                node.right = merge(node1.right, node2)

                return node
            elif node2 and not node1:
                node = TreeNode(node2.val)

                node.left = merge(node1, node2.left)
                node.right = merge(node1, node2.right)

                return node
            else:
                node = TreeNode(node1.val + node2.val)

                node.left = merge(node1.left, node2.left)
                node.right = merge(node1.right, node2.right)

                return node
        
        return merge(root1, root2)