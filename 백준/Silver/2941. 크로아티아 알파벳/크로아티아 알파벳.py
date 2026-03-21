a = input()
crolist = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

for cro in crolist:
  a = a.replace(cro, '*')

print(len(a))