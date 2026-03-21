import sys
input = sys.stdin.readline
for _ in range(3):
    n = int(input())
    num = [int(input()) for _ in range(n)]
    s = sum(num)
    if s == 0:
        print(0)
    elif s > 0:
        print("+")
    else:
        print("-")