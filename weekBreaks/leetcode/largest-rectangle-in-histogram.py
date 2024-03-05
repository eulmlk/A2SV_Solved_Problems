class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        nextSmaller = [n] * n
        prevSmaller = [-1] * n

        stack = []
        for i in range(n):
            while stack and heights[stack[-1]] > heights[i]:
                j = stack.pop()
                nextSmaller[j] = i
            
            if stack:
                prevSmaller[i] = stack[-1]
            stack.append(i)
        
        maxArea = -1
        for i in range(n):
            width = nextSmaller[i] - prevSmaller[i] - 1
            area = width * heights[i]
            maxArea = max(maxArea, area)
        
        return maxArea