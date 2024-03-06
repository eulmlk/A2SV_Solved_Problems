class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        n, m = len(houses), len(heaters)
    
        def tryR(r):
            p1, p2 = 0, 0

            while p1 < n and p2 < m:
                left, right = heaters[p2] - r, heaters[p2] + r

                if left <= houses[p1] and houses[p1] <= right:
                    p1 += 1
                else:
                    p2 += 1
            
            return p1 == n
        
        maxR = max(houses[-1], heaters[-1])
        left, right = 0, maxR

        while left <= right:
            mid = (left + right) // 2

            if tryR(mid):
                right = mid - 1
            else:
                left = mid + 1
        
        return left
        