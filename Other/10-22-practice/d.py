n = int(input())
last = 1
out = []
for i in range(n):
    inp = int(input())
    while(last!=inp): 
        out.append(last) 
        last+=1
    last+=1
if(len(out)==0):
    print('good job')
else:
    for i in out:
        print(i)
