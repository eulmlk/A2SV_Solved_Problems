class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left, right = 0, 0
        zeroCount, oneCount = 0, 0
        n = len(nums)
        maxLen = float('-inf')

        while right < n:
            if nums[right] == 0:
                zeroCount += 1
            else:
                oneCount += 1
            
            while left < n and zeroCount > 1:
                if nums[left] == 0:
                    zeroCount -= 1
                else:
                    oneCount -= 1

                left += 1
                
            maxLen = max(maxLen, right - left)
            right += 1
    
        return maxLen