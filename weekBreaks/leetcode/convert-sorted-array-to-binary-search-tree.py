# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)

        def populate(left, right):
            if left > right:
                return
            
            mid = (left + right) // 2
            node = TreeNode(nums[mid])

            node.left = populate(left, mid - 1)
            node.right = populate(mid + 1, right)

            return node

        return populate(0, n - 1)