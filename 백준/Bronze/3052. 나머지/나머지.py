A = []
for i in range(10):
    n = int(input())
    A.append(n%42)
A = set(A)
print(len(A))