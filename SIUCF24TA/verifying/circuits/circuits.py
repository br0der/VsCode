from collections import deque
from heapq import *

# Written by: Brady Aber
# UCF SI Camp 2024
# 07/16/24
# circuits.py

cnt = 0
for tc in range(int(input())):
    cnt+=1
    n, m, k = map(int, input().split())
    assert(1<=n<=100000)
    assert(1<=m<=200000)
    assert(1<=k<=100000)
    sensors = list(map(int, input().split()))
    for sensor in sensors: assert(1<=sensor<=n) 

    adjacencies = [[] for i in range(n)]
    visited = [-1] * n

    # Lets build our adjacencies for djikstras backwards, so we 
    # find the shortest path from the microcontroller to the sensors,
    # instead of the other way around.
    for i in range(m):
        a, b, w = map(int, input().split())
        assert(1<=a<=n) 
        assert(1<=b<=n) 
        assert(1<=w<=100) 
        a-=1
        b-=1
        adjacencies[b].append((a, w))

    q = []
    heappush(q, (0, 0))

    found = False
    minCost = -1
    # Basic Dijkstras
    while len(q) >= 1:
        currCost, currNode = heappop(q)
        if visited[currNode] != -1:
            continue
        visited[currNode] = currCost

        adjs = adjacencies[currNode]
        for nxtNode, nxtWeight in adjs:
            if visited[nxtNode] != -1:
                continue
            heappush(q, (nxtWeight + currCost, nxtNode))
    
    assert(-1 not in visited) # Something has gone terribly wrong, or the graph isnt connected.

    # Count up shortest distance for all sensors.
    out = 0
    for sensor in sensors:
        out+=visited[sensor-1]
    print(out)