class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        n = len(nums)
        pairs = 0

        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] != nums[j]:
                    continue
                
                if i * j % k == 0:
                    pairs += 1
        
        return pairs