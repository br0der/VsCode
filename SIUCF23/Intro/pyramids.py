nums = []

def func(i, j):
    if i>=j-1:
        return 1
    out = func(i+1,j)
    for idx in reversed(range(i+1, j+1)):
        if nums[idx]==nums[i]:
            temp = func(i+1, idx-1)+2
            out = max(out, temp)
            break
    return out

for tc in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    out = func(0, n-1)
    if out == 1:
        print(0)
    else:
        print(out)
