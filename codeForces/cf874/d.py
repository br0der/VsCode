for tc in range(int(input())):
    n = int(input())
    lis = list(map(int, input().split()))
    if lis == [1]:
        print('1')
    else:
        rightBound, v = max(list(enumerate(lis))[1:], key=lambda x:x[1])
        if rightBound==n-1:
            rightBound=n
        for j in range(rightBound, n):
            print(lis[j], end = ' ')
        print(lis[rightBound-1], end = ' ')
        j = rightBound-2
        while j>0 and lis[j]>lis[0]:
            print(lis[j], end = ' ')
            j-=1
        for i in range(0, j+1):
            print(lis[i], end = ' ')
        print()