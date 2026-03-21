a = input()
a_len = len(a)
result = 0
for i in range(a_len):
  if a[i] in 'ABC':
    result += 3
  elif a[i] in 'DEF':
    result += 4
  elif a[i] in 'GHI':
    result += 5
  elif a[i] in 'JKL':
    result += 6
  elif a[i] in 'MNO':
    result += 7
  elif a[i] in 'PQRS':
    result += 8
  elif a[i] in 'TUV':
    result += 9
  elif a[i] in 'WXYZ':
    result += 10
print(result)