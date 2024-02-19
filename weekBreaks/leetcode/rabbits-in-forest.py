class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        counts = Counter(answers)
        total = 0

        for num, count in counts.items():
            rabbits = num + 1
            total += (num + count) // rabbits * rabbits

        return total