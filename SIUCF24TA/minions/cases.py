from random import randint, shuffle
import random
import string


names = []
scores = []

names.append(["TA_Brady","TA_Thomas","Nicoll","Ben","Kai","Ethan","Janvi","Matvey"])
scores.append([701000000, 490000000, 400000000, 501000000, 350000000, 330000000, 370000000, 27])

names.append(["Thomas","TA_Tyler","TA_Travis","TA_Arup","TA_Brady"])
scores.append([1, 3, 5, 4, 2])

names.append([chr(ord('a')+i) for i in range(26)])
scores.append([randint(1, 1000000000) for i in range(26)])
shuffle(names[-1])
assert(len(set(scores[-1]))==len(scores[-1]))

names.append([chr(ord('a')+i) for i in range(26)])
names[-1].extend(["TA"+chr(ord('a')+i) for i in range(26)])
scores.append([randint(1, 1000000000) for i in range(52)])
shuffle(names[-1])
assert(len(set(scores[-1]))==len(scores[-1]))

names.append(["Taylor", "Tarvis", "tanner", "Tanay", "tATA", "Brady", "Bad-Brady", "TAGlen"])
scores.append([2, 3, 4, 5, 7, 6, 1, 8])

names.append([str(randint(1, 10**20)) for i in range(1000)])
scores.append([randint(1, 10**9) for i in range(1000)])
assert(len(set(scores[-1]))==len(scores[-1]))
assert(len(set(names[-1]))==len(names[-1]))

names.append([("TA" if randint(0, 1) == 0 else "") + str(randint(1, 10**18)) for i in range(1000)])
scores.append([randint(1, 10**9) for i in range(1000)])
assert(len(set(scores[-1]))==len(scores[-1]))
assert(len(set(names[-1]))==len(names[-1]))

names.append([("TA" if randint(0, 1) == 0 else "") + ''.join(random.choices(string.ascii_letters, k=18)) for i in range(1000)])
scores.append([randint(1, 10**9) for i in range(1000)])
assert(len(set(scores[-1]))==len(scores[-1]))
assert(len(set(names[-1]))==len(names[-1]))

# -----

names.append([str(randint(1, 10**20)) for i in range(100000)])
scores.append([randint(1, 10**9) for i in range(100000)])
assert(len(set(names[-1]))==len(names[-1]))

names.append([str(randint(1, 10**20)) for i in range(100000)])
scores.append([randint(1, 10**3) for i in range(100000)])
assert(len(set(names[-1]))==len(names[-1]))

names.append([("TA" if randint(0, 1) == 0 else "") + str(randint(1, 10**18)) for i in range(100000)])
scores.append([randint(1, 10**9) for i in range(100000)])
assert(len(set(names[-1]))==len(names[-1]))

names.append([("TA" if randint(0, 1) == 0 else "") + ''.join(random.choices(string.ascii_letters, k=18)) for i in range(100000)])
scores.append([randint(1, 10**9) for i in range(100000)])
assert(len(set(names[-1]))==len(names[-1]))

names.append([chr(ord('a')+i) for i in range(26)])
names[-1].extend(["TA"+chr(ord('a')+i) for i in range(26)])
scores.append([15*randint(2,4) for i in range(52)])
shuffle(names[-1])

print(len(names))
assert(len(names)==len(scores))
for i in range(len(names)):
    print(len(names[i]))
    assert(len(names[i])==len(scores[i]))
    for j in range(len(names[i])):
        print(names[i][j], scores[i][j])