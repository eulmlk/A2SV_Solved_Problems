class Solution:
    def reverseString(self, s: List[str]) -> None:

        def reverse(left, right):
            if left >= right:
                return

            s[left], s[right] = s[right], s[left]
            reverse(left + 1, right - 1)
        
        n = len(s)
        reverse(0, n - 1)
