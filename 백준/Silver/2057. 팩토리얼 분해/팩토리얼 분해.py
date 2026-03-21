def factorial(n):
    if n == 0:
        return 1
    return n*factorial(n-1)


n = int(input())
f = []
for i in range(21):
    f.append(factorial(i))
if n == 0:
    print("NO")
else:
    for i in range(20, -1, -1):
        if n >= f[i]:
            n -= f[i]
    if n == 0:
        print("YES")
    else:
        print("NO")
