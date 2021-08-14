db = dict()

db["063"] = 0
db["010"] = 1
db["093"] = 2
db["079"] = 3
db["106"] = 4
db["103"] = 5
db["119"] = 6
db["011"] = 7
db["127"] = 8
db["107"] = 9

db2 = ["063", "010", "093", "079", "106", "103", "119", "011", "127", "107"]

while True:
    s = input()
    if s == "BYE":
        break

    A, B = s.split("+")
    B = B[:-1]

    tA = A
    tB = B

    a = 0
    b = 0
    while len(A) > 0:
        a *= 10
        a += db[A[0:3]]
        A = A[3:]
    while len(B) > 0:
        b *= 10
        b += db[B[0:3]]
        B = B[3:]
    c = a+b

    C = ""
    while c > 0:
        C = db2[(c % 10)] + C
        c //= 10
    print(tA, "+", tB, "=", C, sep='')
