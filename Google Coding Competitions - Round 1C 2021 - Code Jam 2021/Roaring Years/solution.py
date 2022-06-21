T = int(input())

for _ in range(T):
    print(f'Case #{_+1}: ', end='')
    Y = str(int(input())+1)
    
    mn = 1e9

    for x in range(1,10**(len(Y) - 1),1):
        Z = "0"
        y = x
        cnt = 0
        while(int(Z) < int(Y)):
            Z += str(y)
            y += 1
            cnt += 1
        if cnt >= 2:
            mn = min(mn, int(Z) - int(Y))

    print(mn + int(Y))
