import sys


def input():
    return sys.stdin.readline().strip()


n = int(input())
people = list(map(int, input().split()))
speeds = list(map(int, input().split()))

maxT = 10 ** 9
step = 10 ** -7


def tryT(t):
    ranges = []

    for person, speed in zip(people, speeds):
        reach = t * speed
        left, right = person - reach, person + reach
        ranges.append((left, right))

    left, right = 1, maxT

    for l, r in ranges:
        if l <= right and r >= left:
            left, right = max(left, l), min(right, r)
        else:
            return False

    return True


left, right = 0, maxT
while left <= right:
    mid = (left + right) / 2

    if tryT(mid):
        right = mid - step
    else:
        left = mid + step

print(left)
