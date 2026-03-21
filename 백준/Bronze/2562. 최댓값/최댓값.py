a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())
g = int(input())
h = int(input())
i = int(input())
iList = [a, b, c, d, e, f, g, h, i]
M = iList[0]
for i in range(len(iList)):
    if iList[i] > M:
        M = iList[i]
cnt = iList.index(M)
print(M)
print(cnt+1)