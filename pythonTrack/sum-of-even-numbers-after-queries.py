class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        result = []
        curSum = sum([num for num in nums if num % 2 == 0])

        for val, index in queries:
            if val % 2 == 0 and nums[index] % 2 == 0:
                    curSum += val
            elif val % 2 == 1:
                if nums[index] % 2 == 0:
                    curSum -= nums[index]
                else:
                    curSum += nums[index] + val

            result.append(curSum)
            nums[index] += val 
        
        return result