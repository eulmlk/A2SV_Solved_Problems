from collections import Counter

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input()))

    prefix = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix[i] = prefix[i - 1] + arr[i - 1]

    indices = Counter()
    count = 0

    for i, num in enumerate(prefix):
        diff = num - i

        if diff in indices:
            count += indices[diff]

        indices[diff] += 1

    print(count)
