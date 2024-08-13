from random import randint, shuffle


fo = open("calendar_small.in", 'w')

def print(s):
    fo.write(str(s)+"\n")

prnt = []

t = 7*30*365//5

prnt.append([1, 7, 30, 365])

prnt.append([7665, 300, 60, 5, 7665])

prnt.append([1, t//3, t//3, t//3, 1])

prnt.append([2*i for i in [7665, 300, 60, 5, 7665]])

prnt.append([100000*i for i in [7665, 300, 60, 5, 7665]])

l = [i for i in range(10, 7661, 10)]

shuffle(l)

prnt.append(l)

l2 = [i for i in range(7665, t, 10)]

shuffle(l2)

prnt.append(l2)

l3 = [i for i in range(7664, t, 10)]

l3[1] = 7666

shuffle(l3)

prnt.append(l3)

l4 = [randint(7665//2, 7664) for i in range(1000)]

shuffle(l4)

l4[0] = 1

l4[-1] = t-1

prnt.append(l4)

l5 = [1 for i in range(1, 1000)]

shuffle(l5)

l5[randint(0, 999)] = t-1

prnt.append(l5)

l6 = [1 for i in range(1, 1000)]

shuffle(l6)

l6[randint(0, 999)] = t*1583

prnt.append(l6)

print(len(prnt))

for i in range(len(prnt)):
    print(len(prnt[i]))
    print(" ".join(map(str, prnt[i])))