class Solution:
    def isValid(self, s: str) -> bool:
        lefts = []

        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                lefts.append(ch)
            elif len(lefts) > 0:
                if lefts[-1] == '(' and ch == ')' or lefts[-1] == '[' and ch == ']' or lefts[-1] == '{' and ch == '}':
                    lefts.pop()
                else:
                    return False
            else:
                return False
        
        return len(lefts) == 0