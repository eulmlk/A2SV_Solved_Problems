class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        
        n = len(num1) - 1
        m = len(num2) - 1
        results = []

        for i in range(n, -1, -1):
            res = "0" * (n - i)
            carry = 0
            a = int(num1[i])

            for j in range(m, -1, -1):
                b = int(num2[j])
                prod = a * b + carry

                res += str(prod % 10)
                carry = prod // 10
                
            if carry != 0:
                res += str(carry)

            results.append(res)
        
        n = len(results[-1])
        product = ""
        carry = 0
        for i in range(n):
            curSum = carry

            for res in results:
                if i < len(res):
                    curSum += int(res[i])
            
            product += str(curSum % 10)
            carry = curSum // 10

        if carry != 0:
            product += str(carry)
        
        return product[::-1]
