from collections import deque

# Written by: Brady Aber
# UCF SI Camp 2024
# 7/16/24
# mangeto.py

# At a high level, we will use BFS and greedily color the graph. This is a good example of two-coloring
for tc in range(int(input())):
    n, c = map(int, input().split())

    adjacencies = [[] for i in range(n)]

    # Filling the graph, making sure our nodes go both ways.
    for i in range(c):
        a, b = map(int, input().split())
        assert(1<=a<=n)
        assert(1<=b<=n)
        a-=1
        b-=1
        adjacencies[a].append(b)
        adjacencies[b].append(a)

    color = [-1 for i in range(n)]

    # Using BFS
    q = deque()
    q.append(0)
    color[0] = 0
    bad = False
    while len(q) > 0:
        curr = q.popleft()
        adj = adjacencies[curr]

        for nxt in adj:
            # If the color is inconsistent
            if color[nxt]!=-1 and color[nxt]==color[curr]:
                bad = True
                # q = deque()
                continue
            # Set the color otherwise
            if color[nxt]==-1:
                color[nxt] = 1 - color[curr]
                q.append(nxt)
    # if -1 in color:
    #     print(tc)
    #     print(color)

    if bad:
        print("Donate to a charity")
    else:
        print("Placement found")
    # print(color)
        