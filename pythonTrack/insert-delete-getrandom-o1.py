class RandomizedSet:

    def __init__(self):
        self.nums = {}
        self.indices = {}

    def insert(self, val: int) -> bool:
        if val in self.nums:
            return False
        
        n = len(self.nums)
        self.nums[val] = n
        self.indices[n] = val
        return True


    def remove(self, val: int) -> bool:
        if val not in self.nums:
            return False
        
        n = len(self.nums) - 1
        k = self.nums[val]
        self.indices[k] = self.indices[n]
        self.nums[self.indices[n]] = k
        self.indices.pop(n)
        self.nums.pop(val)
        return True

    def getRandom(self) -> int:
        n = len(self.nums)
        return self.indices[random.randrange(n)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()