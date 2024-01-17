class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        people = [0] * 1001

        for passengers, left, right in trips:
            people[left] += passengers
            people[right] -= passengers
        
        curSum = 0
        for i in range(1001):
            curSum += people[i]

            if curSum > capacity:
                return False
        
        return True