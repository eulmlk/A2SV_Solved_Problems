class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7

        n = len(arr)
        nextSmaller = [n] * n
        prevSmaller = [-1] * n
        stack = []

        for i in range(n):
            while stack and arr[i] <= arr[stack[-1]]:
                ind = stack.pop()
                nextSmaller[ind] = i
            
            stack.append(i)
        
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and arr[i] < arr[stack[-1]]:
                ind = stack.pop()
                prevSmaller[ind] = i
            
            stack.append(i)
        
        total = 0
        for i in range(n):
            right = nextSmaller[i] - i
            left = i - prevSmaller[i]
            total += arr[i] * right * left

        return total % MOD