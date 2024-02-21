class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        brackets = []

        for ch in s:
            if ch == '(':
                brackets.append(ch)
            else:
                val = brackets.pop()

                if val == '(':
                    brackets.append(1)
                else:
                    total = 0
                    while val != '(':
                        total += val
                        val = brackets.pop()
                    
                    brackets.append(total * 2)
        
        return sum(brackets)