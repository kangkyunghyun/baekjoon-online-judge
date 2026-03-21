n = int(input())
for i in range(n):
    List = list(map(int, input().split()))
    Avg = sum(List[1:]) / List[0]
    A = 0
    for i in List[1:]:
        if i > Avg:
            A += 1
    result = A / List[0] * 100
    print(f'{result:.3f}%')