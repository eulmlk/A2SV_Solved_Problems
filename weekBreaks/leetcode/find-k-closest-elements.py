class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        left, right = 0, n - 1

        while left < right and right - left + 1 > k:
            diff1 = abs(arr[left] - x)
            diff2 = abs(arr[right] - x)

            if diff1 <= diff2:
                right -= 1
            else:
                left += 1
        
        return arr[left:right + 1]