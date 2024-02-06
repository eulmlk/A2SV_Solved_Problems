class Solution:
    def minimumSteps(self, s: str) -> int:
        steps = 0
        n = len(s)

        count = 0
        for i in range(n):
            if s[i] == '1':
                count += 1
            else:
                steps += count

        return steps
