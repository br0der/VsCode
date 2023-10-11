for tc in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    dp = [-1]*n
    def lis(idx):
        if dp[idx]!=-1:
            return dp[idx]
        dp[idx] = 1
        for i in range(idx+1, n):
            if arr[i]>arr[idx]:
                dp[idx] = max(dp[idx], dp[i]+1)
        return dp[idx]
    lis(0)