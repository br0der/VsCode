from random import randint


fo = open('yakp_data.in', "w")

def print(s):
    fo.write(str(s) + '\n')

out = []

for i in range(100):
    out.append([])
    for j in range(20):
        out[-1].append([randint(1000, 1000000000000000), randint(1000, 1000000000000000)])

print(len(out))

for i in range(len(out)):
    print(f"{len(out[i])} {randint(1000, 1000000000000000)}")
    for j in range(len(out[i])):
        print(f"{out[i][j][0]} {out[i][j][1]}")