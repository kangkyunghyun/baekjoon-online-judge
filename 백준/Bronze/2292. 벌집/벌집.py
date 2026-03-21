N = int(input())
wrap = 1
cnt = 1
while N > wrap:
    wrap += 6 * cnt
    cnt += 1
print(cnt)