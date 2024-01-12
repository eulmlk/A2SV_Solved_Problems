class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        left, m = 0, n // 4
        counts = Counter(s)
        minStr = n

        def canBalance():
            return counts['Q'] <= m and counts['W'] <= m and counts['E'] <= m and counts['R'] <= m

        for right in range(n):
            counts[s[right]] -= 1

            while left < n and canBalance():
                minStr = min(minStr, right - left + 1)
                counts[s[left]] += 1
                left += 1

        return minStr