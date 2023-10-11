for tc in range(int(input())):
    n, k, g = map(int, input().split())
    totalSilver = k*g
    optimal = ((g+1)//2) - 1
    if optimal*(n-1)<=totalSilver:
        alt = ((totalSilver-optimal*(n-1))%g)
        ans = optimal*(n-1)
        if alt>=g/2:
            ans -= (g-alt)
        else:
            ans += alt
        print(ans)
    else:
        print(totalSilver)