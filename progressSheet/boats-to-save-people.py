class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()

        left = 0
        right = len(people) - 1
        boats = 0

        while left <= right:
            curSum = people[left] + people[right]
            if curSum <= limit:
                left += 1

            right -= 1         
            boats += 1

        return boats 
