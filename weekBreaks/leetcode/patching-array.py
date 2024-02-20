class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        patches = 0
        cur = 0

        for num in nums:
            if num > n:
                break
            
            while num - 1 > cur:
                cur += cur + 1
                patches += 1
            
            cur += num

        while n > cur:
            cur += cur + 1
            patches += 1
        
        return patches