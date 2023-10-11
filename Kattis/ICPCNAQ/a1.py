a = list(map(int, input().split()))
t = a[0]
k = a[1]
c = a[2]
r = []
for i in range(t):
    r.append(list(map(int, input().split())))

num = 0
count = 0
lastid = -1
for i in range(t):
    id = r[i][1]
    if id == lastid:
        count = count + 1
    else:
        num += min(count, c)
        count = 1
        lastid = id
num += min(count,c)

over = max(0, k - num + 1)
num = 0
count = 0
lastid = -1
for i in range(t):
    if num >= k:
        break
    id = r[i][1]
    if id == lastid:
        count = count + 1
        if count <= c:
            print(r[i][0])
            num = num + 1
        elif over > 0:
            print(r[i][0])
            num = num + 1
            over = over - 1
    else:
        print(r[i][0])
        count = 1
        lastid = id
        num = num + 1



