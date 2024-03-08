import sys
import bisect


def input():
    return sys.stdin.readline().strip()


n = int(input())
arr = list(map(int, input().split()))
q = int(input())
arr.sort()

for _ in range(q):
    coins = int(input())
    print(bisect.bisect_right(arr, coins))