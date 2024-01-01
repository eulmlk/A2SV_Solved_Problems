class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        n = len(arr)
        result = []

        while n:
            maxIndex = arr.index(max(arr[:n]))

            if maxIndex:
                result.append(maxIndex + 1)
                arr[:maxIndex + 1] = arr[:maxIndex + 1][::-1]

            result.append(n)
            arr[:n] = arr[:n][::-1]

            n -= 1

        return result