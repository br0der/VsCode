st = input()
counts = [0, 0, 0]
for s in st:
    if s=='T': counts[0]+=1
    if s=='C': counts[1]+=1
    if s=='G': counts[2]+=1
counts.sort()
out = 0
out+=counts[0]*7
out+=counts[1]*counts[1]
out+=counts[2]*counts[2]
out+=counts[0]*counts[0]
print(out)