for tc in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    i = 0
    j = n-1
    on = True
    while i<=j:
        if (l[i] < l[j] and on) or (l[i] > l[j] and not on):
            print('L', end='')
            i+=1
        else:
            print('R', end='')
            j-=1
        on = not on
    print()