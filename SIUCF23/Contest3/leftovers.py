from math import gcd, lcm


for tc in range(int(input())):
    f1, f2 = input().split()
    f1 = list(map(int, f1.split('/')))
    f2 = list(map(int, f2.split('/')))
    temp = lcm(f1[1], f2[1])
    f1[0]*=temp//f1[1]
    f2[0]*=temp//f2[1]
    out = [f1[0]+f2[0], temp]
    g = gcd(out[0], out[1])
    print(f'{out[0]//g}/{out[1]//g}')
