class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        indices = {}

        for i, ch in enumerate(s):
            indices[ch] = i
        
        left, right = 0, 1
        result = []
        while left < n:
            last = indices[s[left]]

            while right <= last:
                last = max(last, indices[s[right]])
                right += 1
            
            result.append(right - left)
            left = right
            right += 1
        
        return result
