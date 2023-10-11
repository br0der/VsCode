for tc in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    odds = [i for i in a if i%2==1]
    evens = [i for i in a if i%2==0]
    # print(evens, odds)
    if len(odds)==0 or len(evens)==0:
        print('YES')
    else:
        smallestOdd = min(odds)
        smallestEven = min(evens)
        if smallestEven<smallestOdd:
            print('NO')
        else:
            print('YES')