class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        picked = Counter()
        left, n = 0, len(fruits)
        maxPicks = -1

        for right in range(n):
            picked[fruits[right]] += 1

            while left < right and len(picked) > 2:
                picked[fruits[left]] -= 1
                if not picked[fruits[left]]:
                    del picked[fruits[left]]
                
                left += 1
            
            maxPicks = max(maxPicks, right - left + 1)
        
        return maxPicks