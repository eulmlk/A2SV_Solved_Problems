class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        flights = [0] * n

        for left, right, seats in bookings:
            flights[left - 1] += seats

            if right < n:
                flights[right] -= seats
        
        result = [flights[0]]

        for i in range(1, n):
            result.append(result[-1] + flights[i])
        
        return result