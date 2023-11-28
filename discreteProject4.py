import math
dat = [[20, 20], [34, 14], [34, 10], [23, 18]]
def ncr(n, k):
    return math.factorial(n) // \
            (math.factorial(k)*math.factorial(n-k))

s = 0
for i in range(4):
    p = 1
    for j in range(4):
        if i==j:
            p*=ncr(dat[j][0],2)
        else:
            p*=ncr(dat[j][1],2)
    s+=p
for i in range(4):
    for j in range(i+1, 4):
        p = 1
        for k in range(4):
            if k==i or k==j:
                p*=dat[k][0]*dat[k][1]
            else:
                p*=ncr(dat[k][1],2)
        s+=p
denom = ncr(40,2) * ncr(48,2) * ncr(44,2) * ncr(41,2)
# print(s/denom)

def func(a, b):
    return a/b + (a/b)*(a-1)/(b-1) + ((b-a)/b)*a/(b-1)
# print(func(12, 44)/(func(8, 40)+func(18,48)+func(12,44)+func(14,41)))