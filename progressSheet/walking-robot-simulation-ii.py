class Robot:
    def __init__(self, width: int, height: int):
        self.pos = 0
        self.beginning = True
        
        self.width = width
        self.height = height
        
        self.perimeter = 2 * (width + height) - 4
        self.Lshape = width + height - 1
        self.Cshape = 2 * width + height - 2

    def step(self, num: int) -> None:
        self.pos += num
        self.pos %= self.perimeter
        self.beginning = False
        

    def getPos(self) -> List[int]:
        if self.pos < self.width:
            return [self.pos, 0]
        elif self.pos < self.Lshape:
            return [self.width - 1, self.pos - self.width + 1]
        elif self.pos < self.Cshape:
            return [self.Cshape - self.pos - 1, self.height - 1]
        else:
            return [0, self.perimeter - self.pos]

    def getDir(self) -> str:
        if self.beginning:
            return 'East'
        elif self.pos == 0:
            return 'South'
        elif self.pos < self.width:
            return 'East'
        elif self.pos < self.Lshape:
            return 'North'
        elif self.pos < self.Cshape:
            return 'West'
        else:
            return 'South'


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()