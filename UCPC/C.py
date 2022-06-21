from decimal import *
getcontext().prec = 50

a, d, k = map(int, input().split())

ans = Decimal(0)
curr = Decimal(d) / Decimal(100)
prob = curr

while curr < 1:
    print(Decimal(a)*curr)
    ans += Decimal(a)*curr
    curr *= (Decimal(1) + (Decimal(k) / Decimal(100)))
    if(curr > 1):
        curr = Decimal(1)
    prob = (Decimal(1) - prob) * curr

print(ans + Decimal(a)*prob)
