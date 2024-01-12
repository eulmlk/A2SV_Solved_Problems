class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left, n = 0, len(s)
        counts = Counter()
        maxLen = -1

        def cantMakeSame(l, r):
            size = r - l + 1
            
            for ch in counts:
                other = size - counts[ch]
                if other <= k:
                    return False

            return True

        for right in range(n):
            counts[s[right]] += 1

            while left < n and cantMakeSame(left, right):
                counts[s[left]] -= 1
                left += 1
            
            maxLen = max(maxLen, right - left + 1)
        
        return maxLen