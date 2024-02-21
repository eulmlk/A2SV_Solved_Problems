class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs)
        half = n // 2
        costs.sort(key=lambda x: x[0] - x[1])
        
        cost = 0
        for i in range(half):
            a, b = costs[i]
            cost += a
        
        for i in range(half, n):
            a, b = costs[i]
            cost += b

        return cost