class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        
        prev = self.kthGrammar(n - 1, (k + 1) // 2)
        if k % 2 == 0:
            return 1 - prev
        else:
            return prev