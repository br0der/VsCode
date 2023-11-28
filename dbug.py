import sys

sys.setrecursionlimit(100005) 

n, k = map(int, input().split())

val = list(map(int, input().split()))
k = int(k)


min_cost = [float("inf")] * len(val)


def rec_min_cost(start):
    
    if(start == (len(val) - 1)):
        return 0
    if(min_cost[start] != float("inf")):
        return min_cost[start]
    
    
    for j in range(1, k + 1):
        
        if((start+j) <= len(val) - 1):
            cost = abs(val[start] - val[start+j])
            
            min_cost[start] = min(cost + rec_min_cost(start+j), min_cost[start])
        else:
            cost = float("inf")
            min_cost[start] = min(cost , min_cost[start])
    return min_cost[start]
print(rec_min_cost(0))