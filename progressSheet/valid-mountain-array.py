class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        size = len(arr)

        if size < 3:
            return False

        maxIndex = -1
        max_ = float('-inf')

        for index in range(1, size - 1):
            if arr[index] > max_:
                maxIndex = index
                max_ = arr[index]
        
        for index in range(maxIndex):
            if arr[index] >= arr[index + 1]:
                return False
        
        for index in range(maxIndex + 1, size):
            if arr[index] >= arr[index - 1]:
                return False
        
        return True