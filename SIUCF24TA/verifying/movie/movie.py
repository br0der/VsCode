
for _ in range(int(input())):
    n,d = map(int, input().split())
    x = [0] * (d+1)
    x[0] = 1
    ans = 0
    a = 0
    for y in map(int, input().split()):
        a+=1
        for i in reversed(range(max(0,d-y+1))):
            if x[i]:
                x[i+y] = 1
                ans = max(ans, i+y)
    assert(a==n)
    print(d - ans)
    
