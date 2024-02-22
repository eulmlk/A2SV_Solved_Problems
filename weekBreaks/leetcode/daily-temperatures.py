class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        stack = []
        result = [0] * n

        for ind, val in enumerate(temperatures):
            while stack and stack[-1][1] < val:
                i, v = stack.pop()
                result[i] = ind - i
            
            stack.append((ind, val))

        return result