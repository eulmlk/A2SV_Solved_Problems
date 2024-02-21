class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        edges = []

        for i in range(n - 1):
            edges.append(weights[i] + weights[i + 1])
        
        edges.sort()
        k -= 1

        minSum = 0
        for i in range(k):
            minSum += edges[i]
        
        maxSum = 0
        for i in range(n - 2, n - k - 2, -1):
            maxSum += edges[i]
        
        return maxSum - minSum