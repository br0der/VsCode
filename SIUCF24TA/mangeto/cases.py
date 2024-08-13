from random import shuffle


ns = []
connections = []

ns.append(3)
connections.append([(1, 2), (2, 3)])

ns.append(5)
connections.append([(1, 2), (3, 2), (3, 4), (5, 4), (5, 1)])


l = []
nxt = 1
s = 2
for i in range(3):
    for j in range(s):
        l.append((nxt+j, nxt+(j+1)%s))
    if i!=2:
        l.append((nxt, nxt+s))
    nxt+=s
    s+=2
ns.append(max(max([x[0] for x in l]), max(x[1] for x in l)))
connections.append(l)

l = []
nxt = 1
s = 3
for i in range(3):
    for j in range(s):
        l.append((nxt+j, nxt+(j+1)%s))
    if i!= 2: l.append((nxt, nxt+s))
    nxt+=s
    s+=2
ns.append(nxt-1)
connections.append(l)

l = []
nxt = 1
s = 2
for i in range(3):
    for j in range(s):
        l.append((nxt+j, nxt+(j+1)%s))
    if i!=2:
        l.append((nxt, nxt+s))
    nxt+=s
    s+=2
    if i==1:
        s+=1
ns.append(nxt-1)
connections.append(l)

l = []
for i in range(1, 19):
    if i*2 <= 18:
        l.append((i, i*2))
    if i*2 + 1 <= 18:
        l.append((i, i*2 + 1))
ns.append(18)
connections.append(l)
shuffle(connections[-1])

l = []
for i in range(1, 19):
    l.append((i, (i+16)%18+1))
    l.append((i, (i+1)%18+1))
ns.append(18)
connections.append(l)
shuffle(connections[-1])

l = []
for i in range(1, 18):
    l.append((i, i+1))
ns.append(18)
connections.append(l)
shuffle(connections[-1])

l = []
for i in range(2, 19):
    l.append((i, i-1))
ns.append(18)
connections.append(l)
shuffle(connections[-1])

l = []
for i in range(1, 19):
    l.append((i, i%18+1))
ns.append(18)
connections.append(l)
shuffle(connections[-1])

# ----

l = []
nxt = 1
s = 2
for i in range(100):
    for j in range(s):
        l.append((nxt+j, nxt+(j+1)%s))
    if i!=99:
        l.append((nxt, nxt+s))
    nxt+=s
    s+=2
ns.append(nxt-1)
connections.append(l)

l = []
nxt = 1
s = 3
for i in range(100):
    for j in range(s):
        l.append((nxt+j, nxt+(j+1)%s))
    if i!=99:
        l.append((nxt, nxt+s))
    nxt+=s
    s+=2
ns.append(nxt-1)
connections.append(l)

l = []
nxt = 1
s = 2
for i in range(100):
    for j in range(s):
        l.append((nxt+j, nxt+(j+1)%s))
    if i!=99:
        l.append((nxt, nxt+s))
    nxt+=s
    s+=2
    if i==1:
        s+=1

ns.append(nxt-1)
connections.append(l)

l = []
for i in range(1, 100000):
    if i*2 <= 100000:
        l.append((i, i*2))
    if i*2 + 1 <= 100000:
        l.append((i, i*2 + 1))
ns.append(100000)
connections.append(l)
shuffle(connections[-1])

l = []
for i in range(1, 100001):
    l.append((i, (i+99998)%100000+1))
    l.append((i, (i+1)%100000+1))
ns.append(100000)
connections.append(l)
shuffle(connections[-1])

l = []
for i in range(1, 100000):
    l.append((i, i+1))
ns.append(100000)
connections.append(l)
shuffle(connections[-1])

l = []
for i in range(1, 100001):
    l.append((i, i%100000+1))
ns.append(100000)
connections.append(l)
shuffle(connections[-1])

l = []
for i in range(2, 100001):
    l.append((i, i-1))
ns.append(100000)
connections.append(l)
shuffle(connections[-1])

assert(len(ns)==len(connections))
print(len(ns))
for i in range(len(ns)):
    print(ns[i], len(connections[i]))
    for j in range(len(connections[i])):
        print(connections[i][j][0], connections[i][j][1])