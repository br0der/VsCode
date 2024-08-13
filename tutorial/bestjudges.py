cases=int(input())
for i in range(cases):
    judges=int(input())
    lis=[]
    for i in range(judges):
        name,p,v,a,x=input().strip().split()
        p=int(p)
        v=int(v)
        a=int(a)
        x=int(x)
        p=p*10
        v=v*4
        a=a*25
        x=x*7
        score=p+v+a+x
        lis.append([name,score])
    lis.sort(key = lambda x:x[0])
    lis.sort(reverse=True, key=lambda x:x[1])
    
    # lis=lis[::-1]
    
    for i in range(judges):
        print(lis[i][0])
