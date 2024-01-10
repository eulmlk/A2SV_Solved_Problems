class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        counts = Counter()
        maxLen = 0

        left = 0
        for right in range(n):
            counts[s[right]] += 1

            while counts[s[right]] > 1:
                counts[s[left]] -= 1
                left += 1
            
            maxLen = max(maxLen, right - left + 1)
        
        return maxLen