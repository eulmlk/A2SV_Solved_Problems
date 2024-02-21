class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        path = path.split('/')

        for token in path:
            if token == '..':
                if stack:
                    stack.pop()
            elif token and token != '.':
                stack.append(token)

        return '/' + '/'.join(stack)
