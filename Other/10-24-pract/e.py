import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
m, n, p, q = map(int, input().split())
# m, n, p, q = 5, 2, 8, 4 # test case
b = ['a']*m
pq = str(p*q)[::-1]
mn = m - n
lp = len(str(p))
lpq = len(str(pq))
if(lp>n): 
    print("IMPOSSIBLE")
else:
    for i in range(lp):
        b[i] = pq[i]
        # nxt+=1

    rem = 0
    for i in range(lp,m-n+lp):
        x = 0
        if i < lpq:
            x += int(pq[i])
        x += q*int(b[i-lp])
        x += rem
        b[i] = str(x % 10)
        rem = x // 10

    c = str(rem)
    b = b[0:m-n+lp]
    b = b[::-1]
    if (len(b)+len(c)) != m or b[n-len(c)] == "0":
        print("IMPOSSIBLE")
    else:
        print(c, ''.join(b), sep='')