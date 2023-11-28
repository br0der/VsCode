import math

count = int(input())
scores = list(map(int, input().split()))
scores.sort(reverse = True)

l1 = list(map(lambda x: x/100, scores))
l2 = list(map(lambda x: (100-x)/100, scores))
s = [l2[0], l1[0]]

maxn = len(scores)
maxe = 0

for n in range(1, maxn+1):
    e = 0
    for i in range(1,n+1):
        k = math.pow(i, i / n)
        e += k * s[i]
    
    if e > maxe:
        maxe = e
    else:
        break
    
    if n < maxn:
        sn = [l2[n]*s[0]]
        for i in range(1, len(s)):
            sn.append(s[i]*l2[n] + s[i-1]*l1[n])
        sn.append(l1[n]*s[-1])
        s = sn
print(s)
print(maxe)