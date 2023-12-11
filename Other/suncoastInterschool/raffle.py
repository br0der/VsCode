def func(n):
    return (n*(n+1))//2
for tc in range(int(input())):
    n, k = list(map(int, input().split()))
    total = func(n)
    # Idea: instead of looping through each of the people in the raffle, 
    # (O(n) where n = 10^9 is too slow, 10^6 or 7 is the cap for 1 second)
    # you can use the sum of consecutive numbers formula:
    # Sum of all numbers [1:n] = n*(n+1)/2
    # and compute in O(1) time the range of tickets that the ith person will have.
    # Ex n = 6 finding the 20th ticket, you compute the total (21), then binary search
    # to find which person will contain the 20th ticket.
    lo = 1
    hi = n
    ans = -1
    while(lo<=hi):
        mid = (lo+hi)/2
        a = n-mid+1
        b = total-func(a-1)
        if(b>=k):
            hi = mid-1
            ans = mid
        else:
            lo = mid+1
        
    print(ans)