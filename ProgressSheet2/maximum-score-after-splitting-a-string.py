class Solution:
    def maxScore(self, s: str) -> int:
        prefix = []
        onesCount = 0

        for ch in s:
            prefix.append(onesCount)

            if ch == '1':
                onesCount += 1
        
        for i in range(len(prefix)):
            prefix[i] = onesCount - prefix[i]
        
        zeroCount = 0
        maxScore = float('-inf')
        for i in range(len(s)):
            if i > 0:
                score = zeroCount + prefix[i]
                maxScore = max(maxScore, score)
    
            if s[i] == '0':
                zeroCount += 1
        
        return maxScore