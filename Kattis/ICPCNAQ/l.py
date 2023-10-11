dat = list(map(int, input().split()))
n = dat[0]
mn = False
mx = False
for i in range(n-1):
    a = int(input())
    if a==dat[1]: mn = True
    if a==dat[2]: mx = True
if not mn and not mx:
    print(-1)
elif not mn:
    print(dat[1])
elif not mx:
    print(dat[2])
else:
    for i in range(dat[1], dat[2]+1):
        print(i)