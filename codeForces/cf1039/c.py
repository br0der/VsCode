for tc in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    g = True
    m = 1e10
    for i in range(n):
        if l[i]//2 >= m:
            g = False
        m = min(m, l[i])

    print("YES" if g else "NO")