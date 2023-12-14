class FrequencyTracker:

    def __init__(self):
        self.arr = defaultdict(int)
        self.freqs = defaultdict(int)

    def add(self, number: int) -> None:
        old = self.arr[number]
        self.arr[number] += 1
        new = self.arr[number]

        self.freqs[new] += 1
        if self.freqs[old]:
            self.freqs[old] -= 1
        

    def deleteOne(self, number: int) -> None:
        if self.arr[number]:
            old = self.arr[number]
            self.arr[number] -= 1
            new = self.arr[number]

            self.freqs[new] += 1
            if self.freqs[old]:
                self.freqs[old] -= 1
        

    def hasFrequency(self, frequency: int) -> bool:
        return self.freqs[frequency]


# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)


'''
FrequencyTracker()
add(3)
add(3)
add(4)
add(5)
add(5)
add(5)
hasfreq(2)
deleteOne(3)
deleteOne(5)
deleteOne(7)

old = 2
new = 1
{3: 1}
{0: 0, 1: 0, 2: 1}

'''