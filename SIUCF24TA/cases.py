
import random


out = open('permutations/permutations_large.in', 'w')

def print(str):
    out.write(str + '\n')

prnt = []

prnt.append([1])

prnt.append([1, 3, 2])

prnt.append([2, 4, 1, 3, 5])

prnt.append([2, 3, 5, 4, 1])

l = [i for i in range(1, 2001)]
random.shuffle(l)
prnt.append(l)

l = [i for i in range(1, 2001)]
random.shuffle(l)
prnt.append(l)

l = [i for i in range(1, 2001)]
random.shuffle(l)
prnt.append(l)

#perm where 
l = [i for i in range(1, 100001)]
random.shuffle(l)
prnt.append(l)

prnt.append([i for i in range(1, 100001)])

prnt.append([(i+50000)%100000 + 1 for i in range(100000)])

prnt.append([(2*i)%99999 + 1 for i in range(99999)])

prnt.append([(((i//2)*2) + (1+i%2)%2)+1 for i in range(100000)])

prnt.append([(i+9999)%100000 + 1 for i in range(100000)])

prnt.append([(i+1)%100000 + 1 for i in range(100000)])

prnt.append([(i+29309)%53129 + 1 for i in range(53129)])

prnt.append([i+1 if i%2==0 else (i+2)%100000 + 1 for i in range(100000)])

print(str(len(prnt)))

for i in range(len(prnt)):
    print(str(len(prnt[i])))
    print(" ".join(map(str, prnt[i])))


# import random


# out = open('lightning/lightning_small.in', 'w')

# def print(str):
#     out.write(str + '\n')

# prnt = []

# prnt.append([(1, 3), (2, 2), (1, 1)])
# prnt.append([(3, 3), (2, 2), (3, 1)])

# prnt.append([(1, 1), (5, 5), (1, 5), (5, 5)])
# prnt.append([(2, 3), (3, 2), (2, 2), (3, 3)])

# prnt.append([(1, 1), (5, 1)])
# prnt.append([(1, 5), (5, 5)])

# prnt.append([(1, 1), (5, 1)])
# prnt.append([(1, 4), (5, 5)])

# prnt.append([(1, 1), (5, 1)])
# prnt.append([(1, 4), (5, 5), (1, 4)])

# prnt.append([(1, 1), (5, 1)])
# prnt.append([(1, 5), (5, 5), (1, 4)])

# prnt.append([(random.randint(1, 100), random.randint(1, 100)) for i in range(10)])
# prnt.append([(random.randint(1, 100), random.randint(1, 100)) for i in range(10)])

# prnt.append([(random.randint(1, 100), random.randint(1, 100)) for i in range(10)])
# prnt.append([(random.randint(1, 100), random.randint(1, 100)) for i in range(10)])

# # prnt.append([(1, 2), (2, 3), (3, 4), (1, 1), (1, 2)])
# # prnt.append([(2, 1), (1, 3), (5, 1), (2, 1)])

# # prnt.append([(1, 2), (2, 3), (3, 4), (1, 1), (1, 2)])
# # prnt.append([(2, 1), (1, 3), (5, 1), (2, 1)])

# # prnt.append([(10, 10), (10, 11)])
# # prnt.append([(10, 5), (5, 10), (10, 15), (15, 10), (6, 10)])

# # prnt.append([(1, i) for i in range(1, 100)])
# # prnt.append([(100, i) for i in range(1, 100)])

# # prnt.append([(2 if i == 87 else 1, i) for i in range(1, 100)])
# # prnt.append([(100, i) for i in range(1, 100)])

# # prnt.append([(2 if i%2 == 1 else 1, i) for i in range(1, 100)])
# # prnt.append([(99 if i%2 == 0 else 100, i) for i in range(1, 100)])

# # prnt.append([(99 if i%2 == 0 else 100, i) for i in range(1, 100)])
# # prnt.append([(2 if i%2 == 1 else 1, i) for i in range(1, 100)])

# # prnt.append([(i, 2 if i%2 == 1 else 1) for i in range(1, 100)])
# # prnt.append([(i, 99 if i%2 == 0 else 100) for i in range(1, 100)])

# # prnt.append([(1, i) for i in range(1, 1000)])
# # prnt.append([(100, i) for i in range(1, 100)])

# # prnt.append([(1, i) for i in range(1, 100)])
# # prnt.append([(100, i) for i in range(1, 1000)])

# # prnt.append([(1, i) for i in range(1, 2)])
# # prnt.append([(1000000000, i) for i in range(1, 50000)])

# # prnt.append([(2 if i == random.randint(3, 99) else 1, i) for i in range(1, 100)])
# # prnt.append([(random.randint(100000, 1000000), i) for i in range(1, 100)])

# # prnt.append([(random.randint(2, 999) if i%2 == 1 else 1, i) for i in range(1, 100)])
# # prnt.append([(random.randint(1000, 1000000000) if i%2 == 0 else 1000000000, i) for i in range(1, 100)])

# # prnt.append([(random.randint(1000, 1000000000) if i%2 == 0 else 1000000000, i) for i in range(1, 100)])
# # prnt.append([(random.randint(2, 999) if i%2 == 1 else 1, i) for i in range(1, 100)])

# # prnt.append([(i, random.randint(1000, 1000000000) if i%2 == 0 else 1000000000) for i in range(1, 100)])
# # prnt.append([(i, random.randint(2, 999) if i%2 == 1 else 1) for i in range(1, 100)])

# # prnt.append([(1, 3), (2, 2), (1, 1)])
# # prnt.append([(3, 3), (2, 2), (3, 1)])

# print(str(len(prnt)//2))

# for i in range(len(prnt)):
#     print(str(len(prnt[i])))
#     print("\n".join(map(lambda x: f"{x[0]} {x[1]}", prnt[i])))