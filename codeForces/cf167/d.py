from collections import deque 

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
options = [(a[i], a[i]-b[i]) for i in range(n)]
options.sort(key=lambda x: -x[0])

actions = deque()
for option in options:
    while len(actions) > 0 and actions[-1][1] >= option[1]:
        actions.pop()
    actions.append(option)
actions = list(actions)
xp = 0
# print(actions)
for i in range(len(c)):
    take = (c[i]-actions[0][0])//actions[0][1] + 1
    # print(take)
    xp += 2*max(take, 0)
    c[i] -= max(take * actions[0][1], 0)

lis = [0 for i in range(10**6)]
for i in range(len(c)):
    if c[i] >= len(lis):
        raise Exception()
    lis[c[i]] += 1

j = 0
for i in reversed(range(len(lis))):
    # if i < 12:
    #     print(lis[0:12])
    if j >= len(actions):
        break
    while j < len(actions) and actions[j][0] > i:
        j+=1
    if j >= len(actions):
        break
    if i-actions[j][1] >= 0:
        lis[i-actions[j][1]] += lis[i]
    xp += 2*lis[i]
    lis[i] = 0


print(xp)