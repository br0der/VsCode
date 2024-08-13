for tc in range(int(input())):
    n, m = map(int, input().split())
    connections = [set() for i in range(n)]
    for i in range(m):
        u, v, w = map(int, input().split())
        u-=1
        v-=1
        connections[u].add(v)
        connections[v].add(u)

    