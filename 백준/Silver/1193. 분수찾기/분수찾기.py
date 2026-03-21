X = int(input())
line = 1

while X > line:
    X -= line
    line += 1

if line % 2 == 0:
    top = X
    bottom = line - X + 1
else:
    top = line - X + 1
    bottom = X

print(f"{top}/{bottom}")