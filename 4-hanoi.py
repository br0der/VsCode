from functools import cache
import math

dp = []
def F(n, k):
    if k==3: return 2**n - 1
    if n==0: return 0
    if k<=2: return float("inf")
    if n==1: return 1
    if dp[n][k]==-1:
        dp[n][k] = 2*F(n-1, k)+1
        for m in range(1, n-1):
            dp[n][k] = min(dp[n][k], 2*F(m, k)+2*F(n-m, k-1))
        
    return dp[n][k]
n = 10
dp = [[-1 for j in range(2*n)] for i in range(2*n)]

for i in range(0, n):
    # print(i)
    for j in range(3, n):
        print(F(i, j), end = ' ')
    print()

# print(F(99, 100))