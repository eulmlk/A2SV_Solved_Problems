class Solution:
    def freqAlphabets(self, s: str) -> str:
        nums = []

        for ch in s:
            if ch == '#':
                first = nums.pop()
                second = nums.pop()
                nums.append(second * 10 + first)
            else:
                nums.append(int(ch))

        result = ''
        
        for num in nums:
            result += chr(num + 96)
        
        return result