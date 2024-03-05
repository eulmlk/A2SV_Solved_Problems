class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
        left = 0
        n = len(word)
        forbidden = set(forbidden)

        maxLen = -1
        for s in forbidden:
            maxLen = max(maxLen, len(s))

        def isGood(left, right):
            left = max(left - 1, right - maxLen)
            for i in range(right, left, -1):
                if word[i:right+1] in forbidden:
                    return False
            
            return True
        
        longest = -1
        for right in range(n):
            while left < n and not isGood(left, right):
                left += 1
            
            longest = max(longest, right - left + 1)
        
        return longest