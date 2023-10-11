def solve():
    n = int(input())
    air = list(map(int, input().split()))
    air.sort()
    worst = float('inf')
    for i in range(n):
        if air[i]>i+1:
            print('impossible')
            return
        worst = min(worst, air[i]/(i+1))
    print(worst)
    return 

solve()