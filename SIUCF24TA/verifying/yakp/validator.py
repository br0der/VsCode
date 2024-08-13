fi = open("yakp_data.in", "r")

def input():
    return fi.readline()

mx = 0
for tc in range(int(input())):
    mx+=1
    n, t = map(int, input().split())
    assert(1<=n<=20)
    assert(1<=t<=10**15)
    for i in range(n):
        r, v = map(int, input().split())
        assert(1<=r<=10**15)
        assert(1<=v<=10**15)
# assert(mx<=15)

print('all_good')