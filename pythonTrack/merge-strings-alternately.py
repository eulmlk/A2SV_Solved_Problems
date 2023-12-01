class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        word = ''
        n = len(word1)
        m = len(word2)
        i = 0

        while i < min(n, m):
            word += word1[i]
            word += word2[i]
            i += 1
        
        j = i
        while i < n:
            word += word1[i]
            i += 1
        
        while j < m:
            word += word2[j]
            j += 1
        
        return word