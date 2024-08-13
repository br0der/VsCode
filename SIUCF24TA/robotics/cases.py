from random import randint, shuffle


# fi = open("robotics_sample.in", 'r')
fo = open("robotics_large.in", 'w')

# def input():
#     return fi.readline()

def print(s, end = '\n'):
    fo.write(str(s) + end)

r = []
cases = []

r.append(5)
cases.append([
    [1,2],
    [1,3],
    [1,5]
])

r.append(45)
cases.append([
    [2],
    [1,3,4],
    [5,9]
])

r.append(4)
cases.append([
    [2],
    [2],
    [2]
])

r.append(51290792)
cases.append([
    [i*10 for i in range(1, 100)],
    [i*10 for i in range(1, 100)],
    [i*10 for i in range(1, 101)]
])

r.append(99999)
cases.append([
    [i*10 for i in range(1, 100)],
    [i*10 for i in range(1, 100)],
    [1000]
])

r.append(100000)
cases.append([
    [i*10 for i in range(1, 100)],
    [1000],
    [i*10 for i in reversed(range(1, 100))],
])

r.append(199999)
cases.append([
    [i*10 for i in range(1, 100)],
    [i*10 for i in range(1, 100)],
    [1000]
])

shuffle(cases[-1][0])
shuffle(cases[-1][1])

r.append(1000000000)
cases.append([
    [i*10 for i in range(1, 100)],
    [123],
    [i*10 for i in range(1, 100)],  
])

r.append(1000000000)
cases.append([
    [123],
    [i*10 for i in range(1, 100)],
    [i*10 for i in reversed(range(1, 100))],  
])

r.append(100)
cases.append([
    [2, 3],
    [11, 7],
    [7, 3],  
])

r.append(randint(1000000, 1000000000))
cases.append([
    [randint(1, 1000) for i in range(1, 100)],
    [randint(1, 1000) for i in range(1, 100)],
    [randint(1, 1000) for i in range(1, 100)],
])


cases.append([
    [randint(1, 1000) for i in range(1, 100)],
    [randint(1, 1000) for i in range(1, 100)],
    [randint(1, 1000) for i in range(1, 100)],
])
r.append(min(cases[-1][0]) * min(cases[-1][1]) * min(cases[-1][2]))

cases.append([
    [randint(1, 1000) for i in range(1, 100)],
    [randint(1, 1000) for i in range(1, 100)],
    [randint(1, 1000) for i in range(1, 100)],
])
r.append((min(cases[-1][0]) * min(cases[-1][1]) * min(cases[-1][2]))-1)

# -------

r.append(randint(1000000000, 1000000000000000000))
cases.append([
    [randint(1, 1000000) for i in range(1, 1000)],
    [randint(1, 1000000) for i in range(1, 1000)],
    [randint(1, 1000000) for i in range(1, 1000)],
])

cases.append([
    [randint(1, 1000000) for i in range(1, 1000)],
    [randint(1, 1000000) for i in range(1, 1000)],
    [randint(1, 1000000) for i in range(1, 1000)],
])
r.append(min(cases[-1][0]) * min(cases[-1][1]) * min(cases[-1][2]))

cases.append([
    [randint(1, 1000000) for i in range(1, 1000)],
    [randint(1, 1000000) for i in range(1, 1000)],
    [randint(1, 1000000) for i in range(1, 1000)],
])
r.append((min(cases[-1][0]) * min(cases[-1][1]) * min(cases[-1][2]))-1)

r.append(99999999907)
cases.append([
    [8627, 149771],
    [433, 9815],
    [1542, 1181],
])

r.append(1000000000000000000)
cases.append([
    [1, 1000000],
    [1, 1000000],
    [1, 1000000],
])

assert(len(cases)==len(r))
print(len(cases))
for i in range(len(cases)):
    print(f"{len(cases[i][0])} {len(cases[i][1])} {len(cases[i][2])} {r[i]}")
    print(" ".join(map(str, cases[i][0])))
    print(" ".join(map(str, cases[i][1])))
    print(" ".join(map(str, cases[i][2])))