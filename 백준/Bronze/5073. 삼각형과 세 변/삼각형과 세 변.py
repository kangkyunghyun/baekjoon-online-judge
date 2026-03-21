import sys
input = sys.stdin.readline

while True:
    a, b, c = map(int, input().split())
    x = {a, b, c}
    if x == {0}:
        break
    if max(x) >= a + b + c - max(x):
        x = {}
    n = len(x)
    print(['Invalid', 'Equilateral', 'Isosceles', 'Scalene'][n])