for tc in range(int(input())):
    n = int(input())
    lis = list(map(int, input().split()))
    lis.sort()
    total = 0
    i, j = 0, len(lis)-1
    while i<j:
        total+=lis[j]-lis[i]
        j-=1
        i+=1
    print(total)