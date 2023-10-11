n, lph = map(int, input().split())
total_l = lph*5
lis = []
for i in range(n):
    lis.append(int(input()))
lis.sort()
out = 0
for i in range(n):
    if(total_l >= lis[i]):
        total_l -= lis[i]
        out+=1
    else: break
print(out)