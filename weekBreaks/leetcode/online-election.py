class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        leader = -1
        maxVote = -1
        votes = Counter()
        self.people = []

        for person, time in zip(persons, times):
            votes[person] += 1

            if votes[person] >= maxVote:
                leader = person
                maxVote = votes[person]

            self.people.append((time, leader))


    def q(self, t: int) -> int:
        n = len(self.people)
        left, right = 0, n - 1

        while left <= right:
            mid = (left + right) // 2

            if self.people[mid][0] > t:
                right = mid - 1
            else:
                left = mid + 1
        
        return self.people[right][1]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)