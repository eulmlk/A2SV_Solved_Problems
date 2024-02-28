class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letters = {
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz",
        }

        result = []
        cur = []
        n = len(digits)
        def populate(ind):
            if ind == n:
                if cur:
                    result.append(''.join(cur))
                return
            
            for ch in letters[digits[ind]]:
                cur.append(ch)
                populate(ind + 1)
                cur.pop()
        
        populate(0)
        return result
