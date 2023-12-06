class Solution:
    def totalMoney(self, n: int) -> int:
        moneyToPut = 1
        day = 0
        lastMonday = 1
        totalMoney = 0

        for _ in range(n):
            totalMoney += moneyToPut
            
            day = (day + 1) % 7
            if day == 0:
                moneyToPut = lastMonday + 1
                lastMonday = moneyToPut
            else:
                moneyToPut += 1
        
        return totalMoney
            
