class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        m = n - k
        curSum = sum(cardPoints[:m])
        minSum = curSum

        for right in range(m, n):
            curSum += cardPoints[right]
            curSum -= cardPoints[right - m]

            minSum = min(minSum, curSum)
        
        return sum(cardPoints) - minSum