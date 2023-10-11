from collections import defaultdict, deque
adj = defaultdict(set)
colors = []
def diameter(start, constraint=lambda x: 1==1):
    global adj, colors
    q = deque([(start, 0)])
    visited = [False]*len(adj)
    visited[start] = True
    last = start
    lout = 0
    while(q):
        curr, l = q.popleft()
        if(constraint(curr)):
            last = curr
            lout = l
        # print(curr)
        for nxt in adj[curr]:
            if visited[nxt]: continue
            q.append((nxt, l+1))
            visited[nxt] = True
    return (last, lout)


def solve():
    global adj, colors
    n = int(input())
    colors = input()
    adj = defaultdict(set)
    for i in range(n-1):
        a, b = map(int, input().split())
        adj[a-1].add(b-1)
        adj[b-1].add(a-1)
    if(colors==('P'*n)):
        return -1
    if(colors==('G'*n)):
        return -1
    # print(adj)
    end1, temp = diameter(0)
    end2, temp = diameter(end1)
    endout, out = diameter(end1, lambda x: colors[x]!=colors[end1])
    endout1, out1 = diameter(end2, lambda x: colors[x]!=colors[end2])
    # print(end1, temp, end2, out)
    return max(out, out1)

for tc in range(int(input())):
    print(solve())
