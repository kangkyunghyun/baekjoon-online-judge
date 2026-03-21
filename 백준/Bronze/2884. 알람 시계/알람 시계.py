h, m = map(int, input().split())
if m >= 45:
    m -= 45
    print(h, m)
elif m < 45 and h > 0:
    h -= 1
    m = 15 + m
    print(h, m)
else:
    h = 23
    m = 15 + m
    print(h, m)
