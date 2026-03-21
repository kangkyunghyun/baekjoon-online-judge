import sys
input = sys.stdin.readline

n = int(input())
s = ' *' * n
for i in range(n * 2):
    print(s[i % 2 < 1:(i % 2 < 1) + n])