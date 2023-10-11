from collections import defaultdict, deque
with open('data/input.txt') as f:
    lines = f.readlines()
n = 0
clauses = []
for i in range(len(lines)):
    clauses.append(list(map(int, lines[i].strip().split())))
    n = max(max(abs(clauses[-1][0]), abs(clauses[-1][1])), n)

# print(line)
#line = list(map(int, inpxut().split()))

lis = [-1]*(n+1)
adj = defaultdict(set)

for clause in clauses:
    adj[clause[0]*-1].add(clause[1])
    adj[clause[1]*-1].add(clause[0])

nextToSet = 1
works = True

recentlySet = set()
# print(adj[1])
def bfs(start):
    global recentlySet
    q = deque()
    q.append(start)

    if(start<0): lis[abs(start)] = 0
    else: lis[abs(start)] = 1
    while q:
        
        curr = q.popleft()
        
        for xtemp in adj[curr]:
            # print(xtemp, curr)
            if(lis[abs(xtemp)]==0 and xtemp>0): return False
            if(lis[abs(xtemp)]==1 and xtemp<0): return False
            if(lis[abs(xtemp)]!=-1): continue

            if(xtemp<0): lis[abs(xtemp)] = 0
            else: lis[abs(xtemp)] = 1
            recentlySet.add(abs(xtemp))
            q.append(xtemp)
    return True

def clearSet():
    global recentlySet
    for elem in recentlySet:
        lis[elem] = -1
    recentlySet = set()

while nextToSet<=n:
    if(not bfs(nextToSet)): 
        clearSet()
        if(not bfs(-nextToSet)):
            clearSet()
            works = False
            break
    recentlySet = set()
    # nextToSet = abs(nextToSet)
    while abs(nextToSet)<=n and lis[nextToSet]!=-1: 
        nextToSet+=1
        
if works:
    print(lis[1:])
    for i in lis[1:]:
        print((i*2-1), -1*(i*2-1), end = ' ')
    for clause in clauses:
        if(lis[abs(clause[0])]!=(clause[0]>0) and lis[abs(clause[1])]!=(clause[1]>0)):
            print(clause, lis[abs(clause[0])], lis[abs(clause[1])])
            print('Bruh')
            break
    else:
        print('chillin', len(lis))
else:
    print('FALSE')
    