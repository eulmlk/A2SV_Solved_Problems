class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result = []
        cur = []

        def comb(ind, curNum):
            if ind > k:
                return
            
            if ind == k and sum(cur) == n:
                result.append(cur.copy())
                return
            
            for num in range(curNum, 10):
                cur.append(num)
                comb(ind + 1, num + 1)
                cur.pop()
        
        comb(0, 1)
        return result