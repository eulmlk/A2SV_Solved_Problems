class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n, m = len(s), len(p)
        result = []
        counts = Counter(p)

        for i in range(n - m + 1):
            sub = s[i:i + m]

            if Counter(sub) == counts:
                result.append(i)
        
        return result