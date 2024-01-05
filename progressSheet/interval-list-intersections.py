class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        first, second = 0, 0
        n, m = len(firstList), len(secondList)
        result = []

        while first < n and second < m:
            low1, high1 = firstList[first]
            low2, high2 = secondList[second]

            if low1 < low2 and high1 >= low2:
                if high1 > high2:
                    result.append([low2, high2])
                    second += 1
                else:
                    result.append([low2, high1])
                    first += 1
            elif low2 < low1 and high2 >= low1:
                if high1 > high2:
                    result.append([low1, high2])
                    second += 1
                else:
                    result.append([low1, high1])
                    first += 1
            elif low1 == low2:
                if high1 < high2:
                    result.append([low1, high1])
                    first += 1
                else:
                    result.append([low2, high2])
                    second += 1
            elif low1 < low2:
                first += 1
            else:
                second += 1
            
        return result
