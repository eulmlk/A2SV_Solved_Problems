class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        deleted = 0
        rows = len(strs)
        cols = len(strs[0])


        def isSorted(col: int) -> bool:
            for index in range(rows - 1):
                if strs[index][col] > strs[index + 1][col]:
                    return False
            
            return True

        for col in range(cols):
            if not isSorted(col):
                deleted += 1
        
        return deleted