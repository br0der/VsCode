n = int(input())
a = list(map(int, input().split()))
cnt = 2
works = True
bypass = False
for i in range(len(a)):
    if not bypass:
        cnt-=a[i]
        if cnt < 0:
            works = False
            break
        if i!=n-1:
            cnt*=2
        if cnt >= 1<<62:
            bypass=True
            cnt%=1000000007
    else:
        cnt-=a[i]%(1000000007)
        cnt+=1000000007
        cnt%=1000000007
        if i!=n-1:
            cnt*=2
        cnt%=1000000007
    

if works:
    print((cnt)%(1000000007))
else:
    print("error")