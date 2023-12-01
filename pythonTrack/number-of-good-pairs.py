class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        freqs = {}

        for num in nums:
            if num in freqs.keys():
                freqs[num] += 1
            else:
                freqs[num] = 1
        
        possible = 0
        for n in freqs.values():
            possible += n * (n - 1) // 2

        return possible