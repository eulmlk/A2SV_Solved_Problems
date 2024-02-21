class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        def operate(num1, num2, op):
            if op == '+':
                return num1 + num2
            elif op == '-':
                return num1 - num2
            elif op == '*':
                return num1 * num2
            elif op == '/':
                return int(num1 / num2)

        for token in tokens:
            if token in "+-*/":
                right = stack.pop()
                left = stack.pop()
                stack.append(operate(left, right, token))
            else:
                stack.append(int(token))
        
        return stack.pop()