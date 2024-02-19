class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        palindrome = list(palindrome)
        n = len(palindrome)
        half = n // 2

        replaced = False

        for i in range(half):
            if palindrome[i] != 'a':
                replaced = True
                palindrome[i] = 'a'
                break
        
        if replaced:
            return "".join(palindrome)
        
        if n % 2 == 0:
            half -= 1
        
        for i in range(n - 1, half, -1):
            if palindrome[i] != 'b':
                replaced = True
                palindrome[i] = 'b'
                break
        
        if replaced:
            return "".join(palindrome)
        
        return ""
