class DataStream:

    def __init__(self, value: int, k: int):
        self.queue = Deque()
        self.k = k
        self.value = value
        self.counts = 0

    def consec(self, num: int) -> bool:
        self.queue.append(num)
        if num == self.value:
            self.counts += 1
        
        if len(self.queue) > self.k:
            val = self.queue.popleft()
            if val == self.value:
                self.counts -= 1
        
        if len(self.queue) < self.k:
            return False
        
        return self.counts == self.k


# Your DataStream object will be instantiated and called as such:
# obj = DataStream(value, k)
# param_1 = obj.consec(num)