class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        if maxDoubles == 0 or target <= 2:
            return target - 1
        
        moves = 1 + target % 2
        return moves + self.minMoves(target // 2, maxDoubles - 1)