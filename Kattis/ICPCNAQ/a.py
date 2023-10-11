a = list(map(int, input().split()))
t = a[0]
k = a[1]
c = a[2]
r = []
for i in range(t):
    r.append([i]+list(map(int, input().split())))

p = []
q = []
num = 0
count = 0
lastid = -1

r.sort(key=lambda x: x[2])
for i in range(t):
    idd = r[i][2]
    if idd == lastid:
        count = count + 1
    else:
        count = 1
        lastid = idd
    if count <= c:
        p.append(r[i])
    else:
        q.append(r[i])


p.sort(key = lambda x : x[0])
q.sort(key = lambda x : x[0])

if len(p) > k:
    p = p[0:k]
else:
    p = q[0:(k-len(p))]+p
    p.sort(key = lambda x : x[0])

# sort p
for e in p:
    print(e[1])
