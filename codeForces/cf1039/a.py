for tc in range(int(input())):
    n, c = map(int, input().split())
    l = list(map(int, input().split()))
    l.sort(reverse=True)
    i = 0
    b = -1
    o = n
    for i in range(len(l)):
        if l[i] <= c:
            c/=2
            o-=1
    print(o)