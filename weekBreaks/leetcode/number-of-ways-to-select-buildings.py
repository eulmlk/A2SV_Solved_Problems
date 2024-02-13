class Solution:
    def numberOfWays(self, s: str) -> int:
        n = len(s)
        
        zeroLeft = [0] * n
        zeroRight = [0] * n

        oneLeft = [0] * n
        oneRight = [0] * n

        ones, zeroes = 0, 0
        for i in range(n):
            if s[i] == '0':
                zeroes += 1
            else:
                ones += 1
            
            zeroLeft[i] = zeroes
            oneLeft[i] = ones
        
        ones, zeroes = 0, 0
        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                zeroes += 1
            else:
                ones += 1
            
            zeroRight[i] = zeroes
            oneRight[i] = ones
        
        count = 0
        for i in range(1, n - 1):
            if s[i] == '0':
                count += oneLeft[i] * oneRight[i]
            else:
                count += zeroLeft[i] * zeroRight[i]

        return count