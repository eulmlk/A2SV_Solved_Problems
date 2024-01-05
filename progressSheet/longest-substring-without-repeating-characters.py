class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        
        left, right = 0, 0
        n = len(s)
        counts = {}
        maxLen = -inf

        while right < n:
            if s[right] not in counts.keys() or counts[s[right]] == 0:
                counts[s[right]] = 1
                right += 1
            else:
                ch = s[right]
                while counts[ch] != 0:
                    counts[s[left]] -= 1
                    left += 1
            
            maxLen = max(maxLen, right - left)
        
        return maxLen