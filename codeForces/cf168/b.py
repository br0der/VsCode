for tc in range(int(input())):
    n = int(input())
    r1 = input().strip()
    r2 = input().strip()
    
    out = 0
    for i in range(1, n-1):
        # print(r1[i-1:i+2])
        if r1[i-1:i+2]=='...' and r2[i-1:i+2]=='x.x':
            out+=1
        if r2[i-1:i+2]=='...' and r1[i-1:i+2]=='x.x':
            out+=1
    print(out)