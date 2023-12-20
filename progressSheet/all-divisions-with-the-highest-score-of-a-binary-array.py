class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        zeroes, ones = 0, 0
        zeroCounts = [0]
        oneCounts = [0]

        for num in nums:
            if num == 1:
                ones += 1
            else:
                zeroes += 1
            
            zeroCounts.append(zeroes)
            oneCounts.append(ones)
        
        totalOnes = ones

        for index, count in enumerate(oneCounts):
            oneCounts[index] = totalOnes - oneCounts[index]
        
        max_ = float('-inf')
        
        for zeroes, ones in zip(zeroCounts, oneCounts):
            max_ = max(max_, zeroes + ones)
        
        result = []
        index = 0

        for zeroes, ones in zip(zeroCounts, oneCounts):
            if zeroes + ones == max_:
                result.append(index)
            
            index += 1
            
        return result
