for tc in range(int(input())):
    n = int(input())
    lis = list(map(int, input().split()))
    in_run = False
    total = 0
    ranges = 0
    for i in range(n):
        total+=abs(lis[i])
        if lis[i]<0:
            if not in_run:
                in_run = True
                ranges+=1
        elif lis[i]>0:
            if in_run:
                in_run = False
    print(f'{total} {ranges}')
