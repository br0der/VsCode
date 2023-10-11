from bisect import bisect_left


def solve(a, b, c, k):
    sA = int(10**(a-1))
    sB = int(10**(b-1))
    if len(str(sA+sB))<c:
        sC = int(10**(c-1))
        sB = sC - sA
    elif len(str(sA+sB))==c:
        sC = sA+sB
    else:
        return -1
    lis = [0]*(10**a)
    for i in range(sA, 10**a):
        # print(min(10**c - i - 1, int(10**b)-1))
        lis[i] = lis[i-1]+max(min(10**c - i - 1, int(10**b)-1) - max(int(10**(b-1)), 10**(c-1) - i) + 1, 0)
    idx = bisect_left(lis, k)
    if idx >= len(lis):
        return -1
    # print(lis)
    # print(k, lis[idx], idx)
    k-=lis[idx-1]
    sA = idx
    sB = int(10**(b-1))
    if len(str(sA+sB))<c:
        sB = sC - sA + (k-1)
    elif len(str(sA+sB))==c:
        sB += (k-1)
    else:
        return 'what'
    sC = sA + sB
    return f'{sA} + {sB} = {sC}'

for tc in range(int(input())):
    a, b, c, k = map(int, input().split())
    print(solve(a,b,c,k))
