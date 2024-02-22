class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = [0] * n
        right = [0] * n

        curMax = 0
        for i in range(n):
            left[i] = curMax
            curMax = max(curMax, height[i])
        
        curMax = 0
        for i in range(n - 1, -1, -1):
            right[i] = curMax
            curMax = max(curMax, height[i])
        
        trapped = 0
        for i in range(n):
            val = min(left[i], right[i]) - height[i]
            trapped += max(val, 0)

        return trapped