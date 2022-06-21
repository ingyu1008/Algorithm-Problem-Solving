import decimal
decimal.getcontext().prec = 100

N = int(input())
eps = decimal.Decimal(1e-30)

for t in range(N):
    A, B, C, D = map(decimal.Decimal, input().split())
    if A < 0:
        A = -A
        B = -B
        C = -C
        D = -D

    a = 3*A
    b = 2*B
    c = C

    lo = decimal.Decimal(-1e18)
    left = (-b - decimal.Decimal.sqrt(b**2 - 4*a*c))/(2*a)
    right = (-b + decimal.Decimal.sqrt(b**2 - 4*a*c))/(2*a)
    hi = decimal.Decimal(1e18)

    l = lo
    r = left
    lzero = r
    for _ in range(3000):
        m = (l + r) / 2
        Y = A*m**3 + B*m**2 + C*m + D
        if Y >= 0:
            lzero = m
            r = m-eps
        else:
            l = m+eps
    
    l = left
    r = right
    mzero = l
    for _ in range(3000):
        m = (l + r) / 2
        Y = A*m**3 + B*m**2 + C*m + D
        if Y >= 0:
            mzero = m
            l = m+eps
        else:
            r = m-eps

    l = right
    r = hi
    rzero = r
    for _ in range(3000):
        m = (l + r) / 2
        Y = A*m**3 + B*m**2 + C*m + D
        if Y >= 0:
            rzero = m
            r = m-eps
        else:
            l = m+eps

    li = []
    if A*left**3 + B*left**2 + C*left + D >= 0 and A*lzero**3 + B*lzero**2 + C*lzero + D == 0:
        li.append(lzero)
    if A*left**3 + B*left**2 + C*left + D >= 0 and A*right**3 + B*right**2 + C*right + D <= 0 and A*mzero**3 + B*mzero**2 + C*mzero + D == 0:
        li.append(mzero)
    if A*right**3 + B*right**2 + C*right + D <= 0 and A*rzero**3 + B*rzero**2 + C*rzero + D == 0:
        li.append(rzero)
    li.sort()
    if len(li) > 1 and li[1] - li[0] < 1e-5:
        li.pop(1)
    if len(li) > 1 and li[-1] - li[-2] < 1e-5:
        li.pop()
    print(*["%.5f" % x for x in li])