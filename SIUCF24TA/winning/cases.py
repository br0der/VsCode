from random import randint, shuffle


fo = open("winning_large.in", 'w')

def print(s):
    fo.write(str(s)+"\n")

prnt = []

# prnt.append([10, 1, 6, 4, 9, 2])

# prnt.append([1, 3, 5, 4])

# l = [5192307+i for i in range(20)]
# l.append(1)
# prnt.append(l)

# l = [randint(1, 1000000000) for i in range(20)]
# l.append(100000000)
# prnt.append(l)

# l = [i for i in range(20000, 20020)]
# shuffle(l)
# l.append(20)
# prnt.append(l)

# l = [i for i in range(20000, 20020)]
# shuffle(l)
# l.append(9)
# prnt.append(l)

# l = [i for i in reversed(range(200000, 200020))]
# shuffle(l)
# l.append(3)
# prnt.append(l)

# l = [100*i for i in reversed(range(200000, 200020))]
# shuffle(l)
# l.append(4)
# prnt.append(l)

# l = [i for i in range(1, 10)]
# l.extend([i for i in range(100, 110)])
# shuffle(l)
# l.append(9)
# prnt.append(l)

# l = [i for i in range(1, 11)]
# l.extend([i for i in range(101, 111)])
# shuffle(l)
# l.append(8)
# prnt.append(l)

# l = [i for i in range(1, 11)]
# l.extend([i for i in range(101, 111)])
# shuffle(l)
# l.append(2)
# prnt.append(l)



l = [1592*i + 1520  for i in range(100000)]
shuffle(l)
l.append(100000)
prnt.append(l)

l = [i*100000 for i in range(1, 10001)]
l.append(99999)
prnt.append(l)

l = [i for i in reversed(range(200000, 200020))]
shuffle(l)
l.append(3)
prnt.append(l)

l = [100*i for i in reversed(range(200000, 300000))]
shuffle(l)
l.append(4)
prnt.append(l)

l = [i for i in range(1, 50001)]
l.extend([i for i in range(10050001, 10100001)])
shuffle(l)
l.append(49998)
prnt.append(l)

l = [i for i in range(1, 50001)]
l.extend([i for i in range(10050001, 10100001)])
shuffle(l)
l.append(49998//2 - 1)
prnt.append(l)

l = [i for i in range(1, 50001)]
l.extend([i for i in range(10050001, 10100001)])
shuffle(l)
l.append(2)
prnt.append(l)

print(len(prnt))
for line in prnt:
    print(f"{len(line) - 1} {line[-1]}")
    print(" ".join(map(str, line[:-1])))