from datetime import datetime

N = int(input())

if N == 0:
    print(0)
    exit(0)

T = []
L = []

for i in range(N):
    inputs = input().split()
    d = list(map(int, inputs[0].split('/')))
    t = list(map(int, inputs[1].split(':')))
    T.append(datetime(d[0], d[1], d[2], t[0] , t[1], t[2]))
    L.append(int(inputs[2]))

P = []
X = 0
for i in range(N):
    P.append(max(0.9 ** (N-1-i), 0.5 **((T[N-1] - T[i]).total_seconds()/60/60/24/365)))
    X += P[i]*L[i]

X /= sum(P)
print(round(X))