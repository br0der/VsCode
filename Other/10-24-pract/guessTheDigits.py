import sys


sys.set_int_max_str_digits(1000000)
MOD = -1

def gcd(a, b):
    if (b == 0):
        x = 1
        y = 0
        return [a, 1, 0]
    d, x1, y1 = gcd(b, a % b)
    x = y1
    y = x1 - y1 * (a // b)
    return [d, x, y]

def inv(a):
    return gcd(a, MOD)[1]%MOD

m, n, p, q = map(int, input().split())
lx = m-n
lp = len(str(p))
lq = len(str(q))
MOD = int(10**lx)

if lp+lq>m-n:
    print("IMPOSSIBLEa")
else:
    out = (-p*q*inv(int(10**lp)*q-1))%MOD
    out2 = (out*int(10**lp)+p)*q
    if out2%int(10**(m-n))==out:
        print(out2)
    else:
        print("IMPOSSIBLE")
# print(inv(7))
