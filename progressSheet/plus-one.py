class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        size = len(digits)
        sum_, carry = 0, 0

        for index in range(size - 1, -1, -1):
            sum_ = (digits[index] + 1) % 10
            carry = (digits[index] + 1) // 10

            digits[index] = sum_

            if carry == 0:
                break
        
        if carry == 0:
            return digits
        else:
            return [1] + digits