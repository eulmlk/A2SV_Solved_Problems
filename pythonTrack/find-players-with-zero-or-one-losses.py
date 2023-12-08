class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losers = {}
        players = set()

        for winner, loser in matches:
            losers[loser] = losers.get(loser, 0) + 1
            players.add(winner)
            players.add(loser)
        
        undefeated = [player for player in players if player not in losers]
        lostOnes = [player for player in players if player in losers and losers[player] == 1]

        undefeated.sort()
        lostOnes.sort()
        return [undefeated, lostOnes]