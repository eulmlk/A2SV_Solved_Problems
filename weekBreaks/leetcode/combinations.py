class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        cur = []

        def comb(num):
            if len(cur) == k:
                result.append(cur.copy())
                return
            
            if num == n + 1:
                return
            
            cur.append(num)
            comb(num + 1)
            cur.pop()
            comb(num + 1)
        
        comb(1)
        return result