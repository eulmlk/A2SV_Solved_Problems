class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        k = len(s1)
        n = len(s2)
        
        if k > n:
            return False

        counts1 = {ch: 0 for ch in "abcdefghijklmnopqrstuvwxyz"}
        counts2 = {ch: 0 for ch in "abcdefghijklmnopqrstuvwxyz"}
        
        for i in range(k):
            counts1[s1[i]] += 1
            counts2[s2[i]] += 1

        if counts1 == counts2:
            return True
        
        for i in range(k, n):
            counts2[s2[i]] += 1
            counts2[s2[i - k]] -= 1

            if counts1 == counts2:
                return True

        return False
