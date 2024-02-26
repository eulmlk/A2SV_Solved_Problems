class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)

        def evaluate(myTurn, i, j):
            if i > j:
                return float('-inf') if myTurn else float('inf')
            
            if i == j:
                return nums[i] if myTurn else -nums[i]
            
            if myTurn:
                score1 = nums[i] + evaluate(not myTurn, i + 1, j)
                score2 = nums[j] + evaluate(not myTurn, i, j - 1)

                return max(score1, score2)
            else:
                score1 = -nums[i] + evaluate(not myTurn, i + 1, j)
                score2 = -nums[j] + evaluate(not myTurn, i, j - 1)

                return min(score1, score2)
        
        return evaluate(True, 0, n - 1) >= 0