import sys
input = sys.stdin.readline

for _ in range(int(input())):
    x, y = 0, 100
    for i in list(map(int, input().split())):
        if i % 2 == 0:
            x += i
            y = min(y, i)
    print(x, y)