for tc in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    if nums[-1]==1:
        print('NO')
        continue
    out = []
    run = 0
    for i in reversed(range(n)):
        if nums[i]==1:
            out.append('0')
            run+=1
            if i==0 or nums[i-1]==0:
                out.append(f'{run}')
                run = 0
        if nums[i]==0 and (i==0 or nums[i-1]==0):
            out.append('0')
    print('YES')
    print(' '.join(out))