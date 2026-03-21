H, M = map(int, input().split())

if M >= 45:
    print(H, M-45)
elif M < 45 and H < 1:
    print(23, 60 + (M-45))
else:
    print(H-1, 60 + (M-45))