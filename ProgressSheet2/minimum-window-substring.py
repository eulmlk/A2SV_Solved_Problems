class Solution:
    def minWindow(self, s: str, t: str) -> str:
        left, n, m = 0, len(s), len(t)

        if m > n:
            return ""

        sCounts = Counter()
        tCounts = Counter(t)
        minLen = n+1
        index = 0

        def t_in_s():
            for num, count in tCounts.items():
                if num not in sCounts:
                    return False
                
                if count > sCounts[num]:
                    return False
            
            return True

        for right in range(n):
            sCounts[s[right]] += 1

            while left < n and t_in_s():
                size = right - left + 1
                if size < minLen:
                    minLen = size
                    index = left
                
                sCounts[s[left]] -= 1
                left += 1
        
        return s[index:index + minLen] if minLen < n + 1 else ""
