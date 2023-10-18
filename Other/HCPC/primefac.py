from math import sqrt
import string


def factor(num):
    facs = []
    for div in range(2, sqrt(num)):
        while(num%div==0):
            num/=div
            facs.append(div)
    return facs

a = int(input())
while(a!=0):
    f = factor(a)
    f.sort()
    run = 1
    for i in range(len(f)-1):
        if(f[i]!=f[i+1]):
            print(string(f[i]) + '^' + string(run))
            run = 0
        run+=1
    print(string(f[i]) + '^' + string(run))
    a = int(input())