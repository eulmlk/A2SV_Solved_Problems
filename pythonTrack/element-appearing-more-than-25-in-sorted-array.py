class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr) / 4
        freqs = {}

        for num in arr:
            freqs[num] = freqs.get(num, 0) + 1
            if freqs[num] > n:
                return num