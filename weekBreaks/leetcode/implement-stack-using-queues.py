class MyStack:

    def __init__(self):
        self.queue = Deque()
        
    def push(self, x: int) -> None:
        self.queue.append(x)

    def pop(self) -> int:
        temp = Deque()

        while self.queue:
            temp.append(self.queue.popleft())
        
        top = temp.pop()

        while temp:
            self.queue.append(temp.popleft())

        return top

    def top(self) -> int:
        return self.queue[-1]

    def empty(self) -> bool:
        return len(self.queue) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()