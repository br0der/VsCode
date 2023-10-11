# inp = input().split()
b = 5
inv = 19
inp = ["XHQKFBX", "GEX", "HFGE"]
out = [""]*len(inp)
for i in range(len(inp)):
    for ch in range(len(inp[i])):
        c = ord(inp[i][ch])
        c-=ord('A')
        c-=b
        c = (c+26)%26
        c*=inv
        c%=26
        c+=ord('A')
        out[i]+=chr(c)

print(' '.join(out))