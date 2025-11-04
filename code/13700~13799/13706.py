n = int(input())
lo, hi = 0, n
while lo <= hi:
    mid = (lo + hi) // 2
    k = mid * mid
    if k == n:
        print(mid)
        break
    elif k < n:
        lo = mid + 1
    else:
        hi = mid - 1