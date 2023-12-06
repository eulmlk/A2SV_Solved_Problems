class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        minIndex = inf

        for ind, word in enumerate(list1):
            if word in list2:
                next = list2.index(word)
                minIndex = min(minIndex, ind + next)
            
        result = []

        for ind, word in enumerate(list1):
            if word in list2:
                next = list2.index(word)
                
                if next + ind == minIndex:
                    result.append(word)
        
        return result
