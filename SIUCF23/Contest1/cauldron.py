from collections import deque

def solve():
    n, a, b = map(int, input().split())
    potions = []
    for i in range(n):
        t, x = input().split()
        x = int(x)
        potions.append((t, x))
    q = deque([])
    visited = set()
    visited.add(a)
    q.append((a, 0))
    while(q):
        num, l = q.popleft()
        if num==b:
            return l
        for i in range(n):
            if potions[i][0] == 'M':
                nxt = num+potions[i][1]
                if(nxt>=0 and nxt <= 100000 and not nxt in visited):
                    q.append((nxt, l+1))
                    visited.add(nxt)
            if potions[i][0] == 'V':
                nxt = num-potions[i][1]
                if(nxt>=0 and nxt <= 100000 and not nxt in visited):
                    q.append((nxt, l+1))
                    visited.add(nxt)
            if potions[i][0] == 'C':
                nxt = num*potions[i][1]
                if(nxt>=0 and nxt <= 100000 and not nxt in visited):
                    q.append((nxt, l+1))
                    visited.add(nxt)
    return -1

# print('a')
for tc in range(int(input())):
    print(solve())
