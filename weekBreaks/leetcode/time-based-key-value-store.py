class TimeMap:

    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        n = len(self.map[key])
        left, right = 0, n - 1

        while left <= right:
            mid = (left + right) // 2

            if self.map[key][mid][0] > timestamp:
                right = mid - 1
            else:
                left = mid + 1
        
        return self.map[key][right][1] if right > -1 else ""
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)