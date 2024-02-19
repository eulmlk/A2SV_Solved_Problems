class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        lefts = 0
        steps = 0
        
        for ch in s:
            if ch == '(':
                lefts += 1
            elif lefts > 0:
                lefts -= 1
            else:
                steps += 1
        
        steps += lefts
        return steps