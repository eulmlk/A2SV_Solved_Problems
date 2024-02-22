class MyCircularQueue:

    def __init__(self, k: int):
        self.queue = [0] * k
        self.first = -1
        self.last = -1
        self.cap = k

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        
        if self.isEmpty():
            self.first = self.last = 0
            self.queue[self.first] = value
        else:
            self.last = (self.last + 1) % self.cap
            self.queue[self.last] = value
        
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        
        self.first = (self.first + 1) % self.cap
        if self.first == (self.last + 1) % self.cap:
            self.first = -1
            self.last = -1
        
        return True
        

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        else:
            return self.queue[self.first]
        
    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        else:
            return self.queue[self.last]

    def isEmpty(self) -> bool:
        return self.first == -1    

    def isFull(self) -> bool:
        return (self.last + 1) % self.cap == self.first


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()