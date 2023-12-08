class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = ""
        i = 0

        for space in spaces:
            result += s[i:space] + ' '
            i = space
        
        result += s[i:]
        return result