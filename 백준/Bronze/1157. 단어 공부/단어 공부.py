s = input().upper()
a = list(set(s))

count_list = []
for i in a:
    count = s.count(i)
    count_list.append(count)

if count_list.count(max(count_list)) > 1:
    print('?')
else:
    print(a[count_list.index(max(count_list))])