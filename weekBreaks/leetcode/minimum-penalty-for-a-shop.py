class Solution:
    def bestClosingTime(self, customers: str) -> int:
        penalty = 0
        penalties = [penalty]

        for ch in customers:
            penalty += -1 if ch == 'Y' else 1
            penalties.append(penalty)

        minInd, minPen = -1, float('inf')
        for i in range(len(penalties)):
            if penalties[i] < minPen:
                minPen = penalties[i]
                minInd = i

        return minInd
