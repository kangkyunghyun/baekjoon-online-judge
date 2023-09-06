# 2057: 팩토리얼 분해
#
# - 문제
# 음 아닌 정수 N이 주어졌을 때, 이 수를 서로 다른 정수 M(M ≥ 1)개의 팩토리얼의 합으로 나타낼 수 있는지 알아내는 프로그램을 작성하시오. 예를 들어 2=0!+1!로 나타낼 수 있지만, 5는 이와 같은 방식으로 나타낼 수 없다.
#
# - 입력
# 첫째 줄에 정수 N이 주어진다.
#
# - 출력
# 입력으로 주어진 수를 서로 다른 정수 M개의 팩토리얼의 합으로 나타낼 수 있으면 YES, 없으면 NO를 출력한다.
#
# - 제한
# 0 ≤ N ≤ 1,000,000,000,000,000,000

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
