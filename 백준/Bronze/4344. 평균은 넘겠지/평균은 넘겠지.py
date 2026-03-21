n = int(input())
for i in range(n):
    List = list(map(int, input().split()))
    cnt = List[0]
    List.remove(List[0])
    ListAvg = sum(List) / cnt
    OverAvg = []
    for j in List:
        if j > ListAvg:
            OverAvg.append(j)
    result = len(OverAvg) / cnt * 100
    print(f'{result:.3f}%')
