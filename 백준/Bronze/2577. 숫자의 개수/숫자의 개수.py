A = int(input())
B = int(input())
C = int(input())
ABC = str(A*B*C)
print(ABC.count('0'))
for i in range(1, 10):
    print(ABC.count(str(i)))