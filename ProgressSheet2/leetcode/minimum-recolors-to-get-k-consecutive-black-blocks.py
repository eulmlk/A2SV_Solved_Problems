class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n = len(blocks)
        counts = Counter(blocks[:k])
        minRecolors = counts['W']

        for right in range(k, n):
            counts[blocks[right]] += 1
            counts[blocks[right - k]] -= 1

            minRecolors = min(minRecolors, counts['W'])
        
        return minRecolors