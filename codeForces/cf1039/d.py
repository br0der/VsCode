for tc in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    # n = 500000
    # l = [n-i-1 for i in range(n)]
    o = 0
    suff = 0
    maxes = 0
    mx = max(l)
    for i in range(n):
        suff += i+1
        if i>=2 and l[i] < l[i-2] and l[i-1] < l[i-2] and l[i] > l[i-1]:
            suff -= i
        if i==1 and l[i] > l[i-1]:
            suff -= i

        o+=suff
        # if isM:
        #     maxes+=1

        # print(f"i: {i} o: {o} suff: {suff}")
    print(o)