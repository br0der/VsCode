for tc in range(int(input())):
    n, m = map(int, input().split())
    segments = []
    for i in range(m):
        a, b = map(int, input().split())
        segments.append((a-1,b-1))
    changes = []
    for i in range(int(input())):
        changes.append(int(input())-1)
    lo = 0
    hi = len(changes)
    mid = -1
    while lo<hi:
        
        mid = (hi+lo)//2
        good = False
        points = set(changes[:mid+1])
        pSum = [0]*n
        if 0 in points:
            pSum[0] = 1
        for i in range(1, len(pSum)):
            pSum[i] = pSum[i-1]+(1 if i in points else 0)
        # print(pSum)
        for a, b in segments:
            if a == 0:
                if pSum[b]>((b+1)/2):
                    good=True
            else:
                if pSum[b]-pSum[a-1]>((b-a+1)/2):
                    good=True
        # print(lo, hi, good)
        if good:
            hi = mid
        else:
            lo = mid+1
    if lo==len(changes):
        print(-1)
    else:
        print(lo+1)