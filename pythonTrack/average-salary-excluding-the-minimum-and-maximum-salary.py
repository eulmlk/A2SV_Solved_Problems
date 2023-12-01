class Solution:
    def average(self, salary: List[int]) -> float:
        minVal = inf
        maxVal = -inf

        for i in range(len(salary)):
            minVal = min(minVal, salary[i])
            maxVal = max(maxVal, salary[i])
        
        curSum = 0
        for i in range(len(salary)):
            if salary[i] != minVal and salary[i] != maxVal:
                curSum += salary[i]
        
        return curSum / (len(salary) - 2)
