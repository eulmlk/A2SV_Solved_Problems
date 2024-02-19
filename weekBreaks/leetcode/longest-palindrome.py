class Solution:
    def longestPalindrome(self, s: str) -> int:
        counts = Counter(s)
        maxLen = 0
        hasOdd = False

        for ch, count in counts.items():
            maxLen += count // 2 * 2

            if count % 2:
                hasOdd = True
        
        if hasOdd:
            maxLen += 1
        
        return maxLen
