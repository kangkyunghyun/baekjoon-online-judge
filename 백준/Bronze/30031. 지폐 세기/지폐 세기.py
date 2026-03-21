import sys
input = sys.stdin.readline

money = {136 : 1000, 142 : 5000, 148 : 10000, 154 : 50000}
ans = 0
for _ in range(int(input())):
    ans += money[list(map(int, input().split()))[0]]
print(ans)