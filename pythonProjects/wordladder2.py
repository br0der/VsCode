n = int(input())
s = [0]*6
def sToString():
    out = ''
    for c in s:
        out+=chr((c%26)+ord('a'))
    return out

def sGenerator():
    yield sToString()
    first = 1
    for a in range(25):
        for b in range(25):
            for c in range(25):
                s[-1]+=1
                yield sToString()
                s[-2]+=1
                yield sToString()
            s[-3]+=1
            yield sToString()
            s[-4]+=1
            yield sToString()
        s[-5]+=1
        yield sToString()
        s[-6]+=1
        yield sToString()

func = sGenerator()
ans = []
for i in range(n):
    ans.append(next(func))
    print(ans[-1])
for a in range(len(ans)):
    oneOffs = set()
    for b in range(len(ans)):
        if a==b: continue
        if ans[a]==ans[b]:
            print('duplicate')
            exit()
        diffs = 0
        for i in range(6):
            if ans[a][i]!=ans[b][i]: 
                diffs+=1
        if diffs==1:
            oneOffs.add(b)
    print(oneOffs)
