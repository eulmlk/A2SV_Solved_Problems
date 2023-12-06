class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        threshold = n // 3

        counts = dict()
        for num in nums:
            if num in counts.keys():
                counts[num] += 1
            else:
                counts[num] = 1
        
        result = []

        for num in counts.keys():
            if counts[num] > threshold:
                result.append(num)
        
        return result