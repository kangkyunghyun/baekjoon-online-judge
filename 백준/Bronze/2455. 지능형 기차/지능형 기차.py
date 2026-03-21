import sys
input = sys.stdin.readline

now = 0
ans = 0
for _ in range(4):
    a, b = map(int, input().split())
    now -= a
    now += b
    ans = max(ans, now)
print(ans)