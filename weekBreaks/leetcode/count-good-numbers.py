class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        def pow(num, exp):
            if exp == 0:
                return 1
            
            if num == 0 or exp == 1:
                return num
            
            if exp % 2 == 0:
                return pow(num * num % MOD, exp // 2) % MOD
            else:
                return num * pow(num, exp - 1) % MOD
        
        mult = 1
        if n % 2 != 0:
            mult = 5
        
        return mult * pow(20, n // 2) % MOD