class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        candles = []

        for i in range(n):
            if s[i] == '|':
                candles.append(i)
        
        result = []
        print(candles)
        for left, right in queries:
            left = bisect_left(candles, left)
            right = bisect_right(candles, right) - 1

            if left < right:
                candle = right - left
                total = candles[right] - candles[left]
                result.append(total - candle)
            else:
                result.append(0)

        return result