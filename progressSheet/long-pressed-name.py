class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        first, second = 0, 0
        n, m = len(name), len(typed)

        while first < n and second < m:
            base1, base2 = first, second

            if name[first] != typed[second]:
                return False

            first += 1
            while first < n and name[first] == name[first - 1]:
                first += 1
            
            second += 1
            while second < m and typed[second] == typed[second - 1]:
                second += 1
            
            if first - base1 > second - base2:
                return False

        
        return first == n and second == m

