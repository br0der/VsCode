for tc in range(int(input())):
    n = int(input())
    neighbors = list(map(int, input().split()))
    parents = [-1]*n
    size = [1]*n
    def union(a, b):
        a = get(a)
        b = get(b)
        if a==b:
            return
        if size[a]<size[b]:
            a, b = b, a
        parents[b] = a
        size[a]+=size[b]

    def get(a):
        if parents[a]==-1:
            return a
        parents[a] = get(parents[a])
        return parents[a]
        
    for i in range(n):
        union(i, neighbors[i]-1)
    groupHeads = set()
    # print(parents)
    for i in range(n):
        groupHeads.add(get(i))

    # def dfs
    cycles = 0
    visited = [False]*n
    # for i in range(n):

    # print(f'{max(1, degree.count(2))} {len(groupHeads)}')