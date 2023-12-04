class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        cur = capacity
        steps = 0
        for ind, plant in enumerate(plants):
            if cur < plant:
                cur = capacity - plant
                steps += 2 * ind + 1
            else:
                cur -= plant
                steps += 1
        
        return steps