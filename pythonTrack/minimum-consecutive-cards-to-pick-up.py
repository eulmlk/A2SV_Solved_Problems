class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        indices = {}
        n = len(cards)
        minCards = float('inf')

        for index, card in enumerate(cards):
            if card in indices:
                minCards = min(minCards, index - indices[card] + 1)
                
            indices[card] = index
        
        return -1 if minCards == float('inf') else minCards