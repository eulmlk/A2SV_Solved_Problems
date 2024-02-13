class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        n = len(nums)

        leftCounts = [0] * n
        rightCounts = [0] * n

        leftIndices = [0] * n
        rightIndices = [0] * n

        counts = Counter()
        sums = Counter()

        for i in range(n):
            leftCounts[i] = counts[nums[i]]
            leftIndices[i] = sums[nums[i]]

            counts[nums[i]] += 1
            sums[nums[i]] += i
        
        counts = Counter()
        sums = Counter()

        for i in range(n - 1, -1, -1):
            rightCounts[i] = counts[nums[i]]
            rightIndices[i] = sums[nums[i]]

            counts[nums[i]] += 1
            sums[nums[i]] += i
        
        result = []

        for i in range(n):
            left = i * leftCounts[i] - leftIndices[i]
            right = rightIndices[i] - i * rightCounts[i]

            result.append(left + right)

        return result