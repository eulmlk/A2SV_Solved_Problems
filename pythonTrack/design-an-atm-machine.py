class ATM:
    note = [20, 50, 100, 200, 500]

    def __init__(self):
        self.notes = [0] * 5
        

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(5):
            self.notes[i] += banknotesCount[i]
        

    def withdraw(self, amount: int) -> List[int]:
        i = 4
        result = [0] * 5

        while i >= 0 and amount > 0:
            notesCount = min(self.notes[i], amount // self.note[i])
            amount -= notesCount * self.note[i]
            self.notes[i] -= notesCount
            result[i] = notesCount
            i -= 1
        
        if amount == 0:
            return result
        else:
            for i in range(5):
                self.notes[i] += result[i]
            return [-1]


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)