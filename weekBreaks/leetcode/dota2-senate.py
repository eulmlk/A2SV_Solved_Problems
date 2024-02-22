class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        radiants, dires = Deque(), Deque()

        for i, ch in enumerate(senate):
            if ch == 'R':
                radiants.append(i)
            else:
                dires.append(i)
        
        count = len(senate)
        while radiants and dires:
            if radiants[0] < dires[0]:
                radiants.append(count)
            else:
                dires.append(count)
            
            radiants.popleft()
            dires.popleft()
            count += 1

        return "Dire" if dires else "Radiant"