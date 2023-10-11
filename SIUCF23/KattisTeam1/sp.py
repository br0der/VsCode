from functools import lru_cache


dp = []
heights = []
def func(idx, height):
    # print(idx, height)
    if dp[idx][height]!=-1: return dp[idx][height]
    if(idx==len(heights)): 
        if(height==0):
            return ('', 0)
        return ('', -1)
    out = ('', -1)
    other = func(idx+1, height+heights[idx])
    if(height-heights[idx]<0): 
        if other[1]==-1:
            dp[idx][height] = ('', -1)
            return ('', -1)
        dp[idx][height] = ('U'+other[0], other[1])
        return ('U'+other[0], other[1])
    out = func(idx+1, height-heights[idx])
    if out[1]==-1:
        if other[1]==-1:
            dp[idx][height] = ('', -1)
            return ('', -1)
        dp[idx][height] = ('U'+other[0], other[1])
        return ('U'+other[0], other[1])
    if other[1]==-1:
        dp[idx][height] = ('D'+out[0], max(out[1], height))
        return ('D'+out[0], max(out[1], height))
    if other[1]<out[1]:
        dp[idx][height] = ('U'+other[0], other[1])
        return ('U'+other[0], other[1])
    dp[idx][height] = ('D'+out[0], max(out[1], height))
    return ('D'+out[0], max(out[1], height))
    
    
    

for tc in range(int(input())):
    n = int(input())
    dp = [[-1 for i in range(1000)] for j in range(n+1)]
    heights = list(map(int, input().split()))
    out = func(0,0)
    if out[1]==-1:
        print('IMPOSSIBLE')
    print(out[0])
    # print(func(0, 0))