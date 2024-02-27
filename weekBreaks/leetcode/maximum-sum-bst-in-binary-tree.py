# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        maxSum = float('-inf')

        # (maxVal, minVal, sum, isBST)
        def getStats(node):
            nonlocal maxSum

            if not node:
                return (float('-inf'), float('inf'), 0, True)
            
            maxLeft, minLeft, sumLeft, bstLeft = getStats(node.left)
            maxRight, minRight, sumRight, bstRight = getStats(node.right)

            maxCur = max(maxLeft, maxRight, node.val)
            minCur = min(minLeft, minRight, node.val)

            sumCur = 0
            bstCur = False
            if node.val > maxLeft and node.val < minRight and bstLeft and bstRight:
                sumCur = sumLeft + sumRight + node.val
                bstCur = True

            maxSum = max(sumCur, maxSum)
            return (maxCur, minCur, sumCur, bstCur)
        
        getStats(root)
        return max(0, maxSum)