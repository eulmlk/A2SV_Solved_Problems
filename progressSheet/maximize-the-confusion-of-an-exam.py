class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        trueMax = self.maxConsecutives(answerKey, k, 'T')
        falseMax = self.maxConsecutives(answerKey, k, 'F')
        return max(trueMax, falseMax)
    
    def maxConsecutives(self, answerKey, k, letter):
        left, right = 0, 0
        letterCount, otherCount = 0, 0
        n = len(answerKey)
        maxLen = float('-inf')

        while right < n:
            if answerKey[right] == letter:
                letterCount += 1
            else:
                otherCount += 1
            
            while left < n and letterCount > k:
                if answerKey[left] == letter:
                    letterCount -= 1
                else:
                    otherCount -= 1

                left += 1
            
            maxLen = max(maxLen, right - left + 1)
            right += 1
    
        return maxLen