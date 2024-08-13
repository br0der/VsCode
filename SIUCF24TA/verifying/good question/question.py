from math import e, floor, ceil, log2

def eval(n, x):
    if x <= 0:
        return 1
    layers = x
    m = (n-2)//x
    out = 0
    for i in range(x):
        if i < n-m*x:
            out+=log2(m+1)
        else:
            out+=log2(m)
    return out
    

for i in range(1000000, 1000001):
    n = i
    s = (n-2)/e
    print([eval(n,floor(s) + i) for i in range(-20, -4)])
    # x = eval(n,floor(s))
    print([(s+i)*log2(n/(s+i)) for i in range(-2, 3)])

print()