N, K = map(int, input().split())

v = [0 for i in range(3*N + 1)]

for i in range(3, 3*N+1):
    now = (i-1)*(i-2)*(i-3)//6
    v[i] = v[i-1] + now

lo = 3
hi = 3*N

sm = 0
while lo <= hi:
    m = (lo + hi) // 2
    # print(f'{m} {v[m]} {K}')
    if v[m] < K:
        sm = max(sm, m)
        lo = m + 1
    else:
        hi = m - 1

sm += 1

vv = [0 for i in range(3*N + 1)]

for i in range(max(1, sm-2*N), 3*N+1):
    if i+2 > sm:
        vv[i] = vv[i-1]
    else :
        now = sm - i - 1
        vv[i] = vv[i-1] + now

lo = 1
hi = sm - 2
beauty = 0


while lo <= hi:
    m = (lo + hi) // 2
    if v[sm-1] + vv[m] < K:
        beauty = max(beauty, m)
        lo = m + 1
    else :
        hi = m - 1

for taste in range(1, sm - beauty) :
    if v[sm - 1] + vv[beauty] == K:
        print(f'{beauty} {taste} {sm - beauty - taste}')
        break
    K -= 1
