class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        numSet = set(nums)
        cur = Counter()
        n = len(nums)

        total = n * (n + 1) // 2
        left = 0
        count = 0
        for right in range(n):
            cur[nums[right]] += 1

            while left < n and len(cur) == len(numSet):
                cur[nums[left]] -= 1
                if not cur[nums[left]]:
                    del cur[nums[left]]
                
                left += 1

            count += right - left + 1
        
        return total - count