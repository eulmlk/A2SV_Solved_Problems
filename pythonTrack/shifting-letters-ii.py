class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        arr = list(map(lambda x: ord(x) - ord('a'), s))
        updates = [0] * len(arr)

        for left, right, direction in shifts:
            direction = 2 * direction - 1
            updates[left] += direction

            if right + 1 < len(arr):
                updates[right + 1] -= direction
        
        prefix = [updates[0]]
        for i in range(1, len(arr)):
            prefix.append(updates[i] + prefix[-1])

        for i in range(len(arr)):
            arr[i] = (arr[i] + prefix[i]) % 26
        
        return "".join(map(lambda x: chr(x + ord('a')), arr))