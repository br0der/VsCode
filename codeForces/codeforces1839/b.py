for tc in range(int(input())):
    n = int(input())
    lamps = []
    for i in range(n):
        lamps.append(tuple(map(int, input().split())))
    lamps.sort(key = lambda x: -x[1])
    lamps.sort(key = lambda x: x[0])
    broken = -1
    lamps_on = 0
    score = 0
    on = [False]*n
    nxt = 0
    while nxt<n:
        score+=lamps[nxt][1]
        on[nxt] = True
        lamps_on+=1
        off = 0
        while broken+1<n and lamps[broken+1][0]<=lamps_on:
            if on[broken+1]:
                off+=1
            broken+=1
        lamps_on-=off
        nxt+=1
        nxt = max(nxt, broken+1)
    print(score)