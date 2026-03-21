n = int(input())
ans = [1]
for i in range(1, n + 1):
    ans.append(ans[-1] * i)
print(ans[n])