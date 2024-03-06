class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def canShip(capacity):
            curSum = 0
            dayCount = 1

            for weight in weights:
                if curSum + weight > capacity:
                    dayCount += 1
                    curSum = weight
                else:
                    curSum += weight
            
            return dayCount <= days
        
        maxCap = sum(weights)
        minCap = max(weights)
        
        left, right = minCap, maxCap
        while left <= right:
            mid = (left + right) // 2

            if canShip(mid):
                right = mid - 1
            else:
                left = mid + 1
        
        return left
        