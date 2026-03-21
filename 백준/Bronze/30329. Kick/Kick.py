import sys
input = sys.stdin.readline

s = input().strip()
ans = 0
for i in range(len(s) - 3):
    if s[i:i + 4] == 'kick':
        ans += 1
print(ans)