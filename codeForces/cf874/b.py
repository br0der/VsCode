for tc in range(int(input())):
    n, k = map(int, input().split())
    tempsa = list(map(int, input().split()))
    tempsb = list(map(int, input().split()))
    tempsa = list(enumerate(tempsa))
    tempsa.sort(key=lambda x: x[1])
    tempsb.sort()
    out = [-1]*n
    for i in range(n):
        out[tempsa[i][0]] = str(tempsb[i])
    print(' '.join(out))
