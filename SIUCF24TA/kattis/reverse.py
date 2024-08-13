inp = input()

def encr(c):
    if 0<=ord(c)-ord('A')<=25:
        return ord(c)-ord('A')
    if c=='_':
        return 26
    else:
        return 27

def decr(n):
    if 0<=n<=25:
        return chr(n+ord('A'))
    if n==26:
        return "_"
    else:
        return "."

# print([encr(decr(i)) for i in range(28)])

while inp!="0":
    k, s = inp.split()
    k = int(k)
    out = ""
    for j in reversed(range(len(s))):
        out+=decr((encr(s[j])+k)%28)
    print(out)
    inp = input()