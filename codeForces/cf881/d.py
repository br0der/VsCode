from collections import defaultdict, deque
import sys
# sys.setrecursionlimit(400000)

for tc in range(int(input())):
    n = int(input())
    edge = defaultdict(set)
    degrees = [0]*n
    for i in range(n-1):
        a, b = map(int, input().split())
        edge[a-1].add(b-1)
        edge[b-1].add(a-1)
        degrees[a-1]+=1
        degrees[b-1]+=1
    children = [0]*n

    # visited = [False]*n
    # visited[0] = True
    s = deque([i for i in range(len(degrees)) if degrees[i]==1 and i!=0])
    while len(s)>0:
        node = s.pop()
        degrees[node] = 0
        for adj in edge[node]:
            if degrees[adj]==0:
                continue
            degrees[adj]-=1
            children[adj]+=max(1, children[node])
            if degrees[adj]==1 and adj!=0:
                s.appendleft(adj)
    # def dfs(node):
    q = int(input())
    # print(children)
    for i in range(q):
        a, b = map(int, input().split())
        print(max(children[a-1],1)*max(children[b-1],1))
    