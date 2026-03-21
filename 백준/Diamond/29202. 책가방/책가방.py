n, k = map(int, input().split())
ans = 2e18
vec = []
for _ in range(n):
    w, v, t = map(int, input().split())
    vec.append((w, v, t))

bag = []
answer = []
visited = [0] * n


def dfs(depth):
    global ans
    if depth >= k:
        S, M, m = 0, 0, float('inf')
        for i in bag:
            S += vec[i][0]
            M = max(M, vec[i][1])
            m = min(m, vec[i][2])
        if ans > S + M + m:
            ans = S + M + m
            answer[:] = bag
        return
    for i in range(n):
        if not visited[i]:
            visited[i] = 1
            bag.append(i)
            dfs(depth + 1)
            bag.pop()
            visited[i] = 0


dfs(0)
print(ans)
for i in answer:
    print(i + 1, end=' ')
