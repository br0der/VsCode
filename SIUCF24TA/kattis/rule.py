n, l, r = map(int, input().split())
good = dict()
for i in range(8):
    if n&(1<<i):
        good[bin(8+i)[3:]] = True
    else:
        good[bin(8+i)[3:]] = False
# print(good)
s = ('0'*150) + input() + ('0'*150)
for i in range(r):
    out = ""
    for j in range(1,len(s)-1):
        if good[s[j-1:j+2]]:
            out+='1'
        else:
            out+='0'
    print(out[149:149+l])
    s = '0' + out + '0'