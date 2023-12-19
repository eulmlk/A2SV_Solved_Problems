class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        i = 0
        n = len(s)
        result = []

        while i < n:
            sub = s[i:i + k]
            result.append(sub[::-1])
            i += k

            sub = s[i:i + k]
            result.append(sub)
            i += k
        
        return ''.join(result)