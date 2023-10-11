import math

n = int(input())
s = [0]*10
def arrToStr():
    out = ''
    for a in s:
        out+=chr(a+ord('a'))
    return out

key = 0
ans = []
for _ in range(n):
    ans.append(arrToStr())
    print(ans[-1])
    
    j = int(math.log2((key^(key+1))+1)+0.00001)
    print(j)
    j = 10-j
    if s[j]==25:
        s[j]=0
    else:
        s[j]+=1
    key+=1
    
for a in range(len(ans)):
    oneOffs = set()
    for b in range(len(ans)):
        if a==b: continue
        if ans[a]==ans[b]:
            print('duplicate')
            exit()
        diffs = 0
        for i in range(10):
            if ans[a][i]!=ans[b][i]: 
                diffs+=1
        if diffs==1:
            oneOffs.add(b)
    # print(oneOffs)