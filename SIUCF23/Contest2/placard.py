for tc in range(int(input())):
    t, l, h, lp, hp = map(int, input().split())
    lis = [[1 for i in range(l)] for j in range(h)]
    for i in range(t):
        left, bottom, li, hi = map(int, input().split())
        bottom = h-bottom-1
        top = bottom-hi+1
        right = left+li-1
        # print(left, right, bottom, top)
        for y in range(max(0, top-hp+1), bottom+1):
            for x in range(max(0, left-lp+1), right+1):
                # print(y, x)
                lis[y][x] = 0
    out = 0
    for i in range(h-hp+1):
        for j in range(l-lp+1):
            out+=lis[i][j]
    print(out)
