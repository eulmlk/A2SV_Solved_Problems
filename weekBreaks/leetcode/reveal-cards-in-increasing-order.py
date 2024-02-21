class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        n = len(deck)
        deck.sort(reverse=True)
        queue = Deque()

        for card in deck:
            if len(queue) > 1:
                back = queue.pop()
                queue.appendleft(back)
            
            queue.appendleft(card)
        
        return list(queue)