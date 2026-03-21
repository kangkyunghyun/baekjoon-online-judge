import sys
input = sys.stdin.readline

n, m = map(int, input().split())
num = [0] * n
for _ in range(m):
    a, b, c = map(int, input().split())
    for i in range(a - 1, b):
        num[i] = c
print(*num)