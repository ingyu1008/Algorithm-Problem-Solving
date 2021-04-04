import sys
pin = sys.stdin.readline

out = ""

for T in range(int(pin())):
    N = int(pin())
    A = [*map(int,pin().split())]
    for i in range(N):
        p = A[i]
        s = 0
        n = 0
        while 1:
            s += 1
            n += 1
            if n == N: break
            if i+1 == p: break
            p = A[p-1]
        out = out + str(s) + " "
    out = out + "\n"
print(out)