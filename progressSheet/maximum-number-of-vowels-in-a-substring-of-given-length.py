class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowelCount = 0
        maxCount = float('-inf')
        size = len(s)

        def isVowel(ch):
            return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'

        for index in range(k - 1):
            if isVowel(s[index]):
                vowelCount += 1

        for index in range(size - k + 1):
            if isVowel(s[index + k - 1]):
                vowelCount += 1

            maxCount = max(maxCount, vowelCount)

            if isVowel(s[index]):
                vowelCount -= 1
        
        return maxCount