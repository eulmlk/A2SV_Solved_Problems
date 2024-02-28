# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)

        def populate(left, right):
            if left > right:
                return
            
            maxIndex = left
            maxVal = nums[left]
            for i in range(left + 1, right + 1):
                if nums[i] > maxVal:
                    maxVal = nums[i]
                    maxIndex = i
            
            node = TreeNode(maxVal)

            node.left = populate(left, maxIndex - 1)
            node.right = populate(maxIndex + 1, right)

            return node

        return populate(0, n - 1)