n = int(input())
array = list(map(int, input().split()))
iMax = max(array)
array1 = []
for i in range(n):
    array1.append(array[i] / iMax * 100)
average = sum(array1) / n
print(average)