from math import ceil, sqrt
import sys

sys.setrecursionlimit(1010)

dp = []

def func(l, t):
    if t == 1:
        dp[l][t] = l
        return l
    if dp[l][t] == -1:
        dp[l][t] = l
        for i in range(1, l):
            dp[l][t] = min(dp[l][t], max(func(i - 1, t - 1), func(l - i, t)) + 1)
    return dp[l][t]

def run(lis):
    out = [1]
    for i in range(1, len(lis)):
        if lis[i] == lis[i-1]:
            out[-1]+=1
        else:
            out.append(1)

    return out

dp = []
for i in range(1001):
    dp.append([-1 for j in range(501)])

for i in range(500):
    func(i, 9)

# [print(f"{i}: {dp[i][3]}, {ceil((-1 + sqrt(1 + 8*i))/2)}") for i in range(1, 100)]
# [print(f'{j}: {run([dp[i][j] for i in range(1, 400)])[0:9:]}') for j in range(1, 5)]

# print([dp[i][3] for i in range(1, 51)])

n = 10000000000001
k = 100

runLens = [[], []]

runLens.append([])
s = 0
while s <= n:
    runLens[-1].append(len(runLens[-1])+1)
    s+=runLens[-1][-1]

for i in range(3, k+1):
    runLens.append([1])
    s = 1
    while s <= n:
        runLens[-1].append(runLens[-1][-1] + runLens[-2][len(runLens[-1]) - 1])
        s += runLens[-1][-1]

# [print(runLens[i]) for i in range(len(runLens))]
    
def calculate(n, k):
    if k == 1:
        return n
    lo = 0
    hi = len(runLens[k]) - 1
    ans = -1
    while lo <= hi:
        mid = (lo + hi)//2
        s = sum(runLens[k][:(mid + 1)])
        if s < n:
            lo = mid + 1
        else:
            ans = mid
            hi = mid - 1
    return ans + 1

# for i in range(1, 1000):
#     print(func(i, 5), calculate(i, 5))

print(calculate(n - 1, 4))