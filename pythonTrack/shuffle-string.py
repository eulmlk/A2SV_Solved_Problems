class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        n = len(indices)
        arr = [''] * n

        for ind, num in enumerate(indices):
            arr[num] = s[ind]
        
        return "".join(arr)