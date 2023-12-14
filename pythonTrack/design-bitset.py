class Bitset:

    def __init__(self, size: int):
        self.bitset = ['0'] * size
        self.size = size
        self.flips = 0
        self.ones = 0

    def fix(self, idx: int) -> None:
        if self.flips % 2:
            if self.bitset[idx] == '1':
                self.ones += 1
                self.bitset[idx] = '0'
        else:
            if self.bitset[idx] == '0':
                self.ones += 1
                self.bitset[idx] = '1'

    def unfix(self, idx: int) -> None:
        if self.flips % 2:
            if self.bitset[idx] == '0':
                self.ones -= 1
                self.bitset[idx] = '1'
        else:
            if self.bitset[idx] == '1':
                self.ones -= 1
                self.bitset[idx] = '0'

    def flip(self) -> None:
        self.flips += 1
        self.ones = self.size - self.ones

    def all(self) -> bool:
        return self.ones == self.size
        

    def one(self) -> bool:
        return self.ones

    def count(self) -> int:
        return self.ones

    def toString(self) -> str:
        if self.flips % 2:
            for i in range(self.size):
                self.bitset[i] = '1' if self.bitset[i] == '0' else '0'
            
            self.flips = 0
        
        return "".join(self.bitset)


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()