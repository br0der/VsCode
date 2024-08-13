for tc in range(int(input())):
    n, k = map(int, input().split())
    lis = list(map(int, input().split()))
    on = list(map(int, input().split()))
    lis = list(zip(lis, on))
    lis.sort()
    # print(lis)
    onNum = [lis[idx][0] for idx in filter(lambda x: lis[x][1]==1, [i for i in range(n)])]
    # print(onNum)
    mxlis0 = max(lis)[0]
    if onNum == []:
        print(mxlis0 + lis[len(lis)//2 - 1][0])
        continue
    tobeat = mxlis0 + lis[len(lis)//2 - 1][0]
    if max(onNum) > lis[len(lis)//2 - 1][0]:
        tobeat = max(tobeat, max(max(onNum) + k, mxlis0) + lis[len(lis)//2 - 1][0])
    else:
        tobeat = max(tobeat, max(max(onNum) + k, mxlis0) + lis[len(lis)//2][0])
    
    nxt = len(lis)//2 - 1
    med = lis[nxt][0]
    weight = 0
    backwards = nxt-1
    while nxt < len(lis)-1:
        idx = -1

        if lis[nxt][1]==1:
            idx = nxt
        else:
            while backwards >= 0:
                if lis[backwards][1]==1:
                    idx = backwards
                    backwards-=1
                    break
                backwards-=1
            if idx == -1:
                break
        assert(med >= lis[idx][0])
        if k <= med-lis[idx][0]:
            break
        k-=med-lis[idx][0]
        # print(idx)
        weight+=1
        nxt+=1
        # print(med, lis[nxt][0], k, weight)
        if nxt >= n-1:
            if weight >= (len(lis)+1)//2:
                med+=k//weight
            break
        if k <= (lis[nxt][0]-med)*weight:
            med+=k//weight
            break
        k-=(lis[nxt][0]-med)*weight
        med = lis[nxt][0]
        # print(med, lis[nxt][0], k, weight)
    
    # if med > mxlis0: assert(tobeat>mxlis0 + med)
    print(max(mxlis0 + med, tobeat))

    # if mxlis0 + med > tobeat:
    #     print(mxlis0 + med)
    # else:
    # print(tobeat)