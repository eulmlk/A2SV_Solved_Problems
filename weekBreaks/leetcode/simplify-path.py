class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []

        for token in path.split('/'):
            if token == '..':
                if stack:
                    stack.pop()
            elif token and token != '.':
                stack.append(token)

        return '/' + '/'.join(stack)
