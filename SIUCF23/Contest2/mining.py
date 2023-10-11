for tc in range(int(input())):
    n, q = map(int, input().split())
    lis = []
    for i in range(n):
        lis.append(list(map(int, input().split())))
    newLis = [[0 for i in range(2*n-1)] for j in range(2*n-1)]
    for i in range(n):
        for j in range(n):
            newLis[i+j][(2*n-1)//2 + (j-i)] = int(lis[i][j])
    pSum = [[0 for i in range(2*n-1)] for j in range(2*n-1)]
    for i in range(2*n-1):
        for j in range(2*n-1):
            out = newLis[i][j]
            if j!=0: out += pSum[i][j-1]
            if i!=0: out += pSum[i-1][j]
            if j!=0 and i!=0:
                out-=pSum[i-1][j-1]
            pSum[i][j] = out
    # print(pSum)
    # print(newLis)
    for i in range(q):
        r, c, s = map(int, input().split())
        r-=1
        c-=1
        r, c = c, r
        newR = r+c
        newC = (2*n-1)//2 + (c-r)
        newR+=s
        newC+=s
        out = pSum[newR][newC]
        step = 2*(s+1) - 1
        if newR-step >= 0:
            out-=pSum[newR-step][newC]
        if newC-step >= 0:
            out-=pSum[newR][newC-step]
        if newR-step >= 0 and newC-step >= 0:
            out+=pSum[newR-step][newC-step]
        print(out)
