from functools import cache
import itertools, math

def partA(n):
    lis = [i for i in range(2*n)]
    cnt = 0
    perms = list(itertools.permutations(lis))
    for it in perms:
        works = True
        for i in range(n):
            if abs(it[2*i]-it[2*i+1])==1 and min(it[2*i], it[2*i+1])%2==0:
                works = False
        if works: cnt+=1
    return cnt

R = [1, 0, 16]
for i in range(20):
    R.append(R[-1]*len(R)*(len(R)-1)*4)
# print(R)

def ncr(n, k):
    return math.factorial(n) // \
                (math.factorial(k)*math.factorial(n-k))

def partB(n):
    if n<=3: return R[n]
    out = R[n]
    for i in range(1, n):
        out +=  R[i] * \
                partB(n-i) * \
                ncr(n, i) * \
                ncr(n-1, i-1)
    return out

def partC(n):
    T = [0, 16]
    for i in range(n-2):
        currN = len(T)+1
        pt1 =   T[-1] * \
                currN * \
                (currN-1) * \
                4
        pt2 =   T[-2] * \
                (currN-1) * \
                ((currN*(currN-1))//2) * \
                16
        T.append(pt1+pt2)
    return T[n-1]


# print(partC(int(input())))
cnt = 0
for i in range(1, 500):
    if (i%6==0 or i%8==0) and (not i%9==0) and (not i%15==0):
        # print(i)
        cnt+=1
# print(cnt)
# print(10**8-ncr(8,2))
# print(ncr(17, 10))

@cache
def func(x):
    if x == 0:
        return 1
    cnt = 0
    cnt+=func(x-1)
    if x>=2:
        cnt+=func(x-2)
    if x>=5:
        cnt+=func(x-5)
    return cnt

for i in range(1, 11):
    print(i, partC(i))
print(partC(500))