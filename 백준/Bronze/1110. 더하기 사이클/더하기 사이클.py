a = int(input())
first_a = a
n = 0
while True:
    b = a // 10
    c = a % 10
    d = (b + c) % 10
    a = c * 10 + d
    n += 1
    if a == first_a:
        break
print(n)