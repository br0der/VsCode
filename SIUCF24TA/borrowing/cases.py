from random import randint, shuffle


fi = open("borrowing_large.in", 'r')
fo = open("borrowing_small.in", 'w')

def input():
    return fi.readline()

def print(*s, end = '\n'):
    fo.write(" ".join(str(i) for i in s) + end)

ks = [4, 32]
people = [[1,2], [1, 5, 15, 10, 5]]

ks.append(1000000)
people.append([i for i in range(1, 1001)])
shuffle(people[-1])

ks.append(1000000)
people.append([1000 for i in range(1, 1001)])

ks.append(1000000)
people.append([500 + i//2 for i in range(1, 1001)])
shuffle(people[-1])

ks.append(400*801)
people.append([i for i in range(1, 1001)])

ks.append(294)
people.append([1 for i in range(294)])

ks.append(294)
people.append([1 for i in range(295)])

ks.append(randint(1, 1000000))
people.append([randint(1, 1000) for i in range(1000)])

ks.append(1000000)
people.append([1000])

# -----

# ks.append(1000000000)
# people.append([1000000000])

# ks.append(1000000000)
# people.append([i for i in range(1, 100001)])
# shuffle(people[-1])

# ks.append(1000000000)
# people.append([999999999 for i in range(1, 100001)])

# ks.append(1000000000)
# people.append([50000 + i//2 for i in range(1, 100001)])
# shuffle(people[-1])

# ks.append(20000*40001)
# people.append([i*10000 for i in range(1, 100001)])
# shuffle(people[-1])

# ks.append(69420)
# people.append([1 for i in range(69420)])

# ks.append(69420)
# people.append([1 for i in range(69421)])

# ks.append(randint(1, 1000000000))
# people.append([randint(1, 1000000000) for i in range(100000)])

print(len(people))
for i in range(len(ks)):
    print(len(people[i]), ks[i])
    print(" ".join(map(str, people[i])))