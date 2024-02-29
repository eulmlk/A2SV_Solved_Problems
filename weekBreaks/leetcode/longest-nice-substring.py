class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        letters = set(s)
        n = len(s)

        for i in range(n):
            if s[i].swapcase() not in letters:
                left = self.longestNiceSubstring(s[:i])
                right = self.longestNiceSubstring(s[i + 1:])

                if len(left) < len(right):
                    return right
                else:
                    return left
        
        return s
