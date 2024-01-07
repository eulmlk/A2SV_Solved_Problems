class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left, right = 0, 0
        zeroCount, oneCount = 0, 0
        n = len(nums)
        maxLen = float('-inf')

        while right < n:
            if nums[right] == 0:
                zeroCount += 1
            else:
                oneCount += 1
            
            while left < n and zeroCount > k:
                if nums[left] == 0:
                    zeroCount -= 1
                else:
                    oneCount -= 1

                left += 1
            
            maxLen = max(maxLen, right - left + 1)
            right += 1
    
        return maxLen