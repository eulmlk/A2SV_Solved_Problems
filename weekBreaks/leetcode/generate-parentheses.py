class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        cur = []

        def generate(ind, left, right):
            if ind == 2 * n:
                if left == right:
                    result.append(''.join(cur))
                return
            
            if left <= right:
                cur.append('(')
                generate(ind + 1, left + 1, right)
                cur.pop()
            else:
                cur.append(')')
                generate(ind + 1, left, right + 1)
                cur.pop()

                cur.append('(')
                generate(ind + 1, left + 1, right)
                cur.pop()
        
        generate(0, 0, 0)
        return result