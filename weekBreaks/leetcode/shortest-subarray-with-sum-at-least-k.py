class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        minLen = n + 1

        for i in range(1, n):
            nums[i] += nums[i - 1]

        queue = Deque()
        curSum = 0
        minLen = n + 1

        for i in range(n):
            while queue and nums[queue[-1]] > nums[i]:
                j = queue.pop()
            
            queue.append(i)

            while queue and nums[queue[-1]] - nums[queue[0]] >= k:
                curSum = nums[queue[-1]] - nums[queue[0]]
                curLen = queue[-1] - queue[0]

                minLen = min(minLen, curLen)
                queue.popleft()
            
            if nums[i] >= k:
                minLen = min(minLen, i + 1)
        
        return minLen if minLen != n + 1 else -1