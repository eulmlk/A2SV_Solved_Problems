class UndergroundSystem:

    def __init__(self):
        self.checkedIn = {}
        self.travels = defaultdict(list)

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkedIn[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, startTime = self.checkedIn[id]
        self.travels[(startStation, stationName)].append(t - startTime)
        self.checkedIn.pop(id)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        travels = self.travels[(startStation, endStation)]
        return sum(travels) / len(travels)

# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)