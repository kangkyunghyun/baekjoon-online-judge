import sys
input = sys.stdin.readline

n, m = map(int, input().split())
num = list(range(n + 1))
for _ in range(m):
    a, b = map(int, input().split())
    num[a], num[b] = num[b], num[a]
print(*num[1:])