from random import randint, shuffle


words = []
ciphers = []
ks = []

words.append("abcdef")
ciphers.append("bcdefghijklmnopqrstuvwxyza")
ks.append("6")

words.append("bradyssn")
ciphers.append("badcfehgjilknmporqtsvuxwzy")
ks.append("1")

words.append("problemanextcontestis")
ciphers.append("abcdefghijklmnopqrstuvwxyz")
ks.append("100")

words.append("".join([chr(ord('a') + (i%26)) for i in range(100)]))
l = [chr(ord('a') + i) for i in range(26)]
shuffle(l)
ciphers.append("".join(l))
ks.append(1000)

# 2, 3, 5, 7, 9
alph = [chr(ord('a')+i) for i in range(26)]
last = 0

l = [8, 3, 5, 7, 3]
build = []
for num in l:
    l2 = alph[last:last+num]
    shuffle(l2)
    build.extend(l2)
    last+=num

words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(100)]))
ciphers.append("".join(build))
ks.append(999)

l = [7, 5, 3, 8, 3]
build = []
ls = []
last = 0
for num in l:
    l2 = alph[last:last+num]
    shuffle(l2)
    ls.append(l2)
    last+=num
shuffle(ls)
for lis in ls:
    build.extend(lis)
words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(100)]))
ciphers.append("".join(build))
ks.append(998)

l = [i for i in range(26)]
shuffle(l)
words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(97)]))
ciphers.append("".join([chr(ord('a') + l[i]) for i in range(26)]))
ks.append(997)

l = [i for i in range(26)]
shuffle(l)
words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(randint(1,100))]))
ciphers.append("".join([chr(ord('a') + l[i]) for i in range(26)]))
ks.append(randint(1, 1000))

l = [i for i in range(26)]
shuffle(l)
words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(randint(1,100))]))
ciphers.append("".join([chr(ord('a') + l[i]) for i in range(26)]))
ks.append(randint(1, 1000))

# -----

# words.append("".join([chr(ord('a') + (i%26)) for i in range(20000)]))
# l = [chr(ord('a') + i) for i in range(26)]
# shuffle(l)
# ciphers.append("".join(l))
# ks.append(1000000000)

# # 2, 3, 5, 7, 9
# alph = [chr(ord('a')+i) for i in range(26)]
# last = 0

# l = [8, 3, 5, 3, 7]
# build = []
# for num in l:
#     l2 = alph[last:last+num]
#     shuffle(l2)
#     build.extend(l2)
#     last+=num

# words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(20000)]))
# ciphers.append("".join(build))
# ks.append(999999999)

# last = 0
# l = [3, 3, 3, 3, 3, 3, 3, 3, 2]
# build = []
# ls = []
# last = 0
# for num in l:
#     l2 = alph[last:last+num]
#     shuffle(l2)
#     ls.append(l2)
#     last+=num
# shuffle(ls)
# for lis in ls:
#     build.extend(lis)

# words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(20000)]))
# ciphers.append("".join(build))
# ks.append(999999999)

# l = [7, 5, 8, 3, 3]
# build = []
# ls = []
# last = 0
# for num in l:
#     l2 = alph[last:last+num]
#     shuffle(l2)
#     ls.append(l2)
#     last+=num
# shuffle(ls)
# for lis in ls:
#     build.extend(lis)
# words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(20000)]))
# ciphers.append("".join(build))
# ks.append(999999999)

# l = [i for i in range(26)]
# shuffle(l)
# words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(19723)]))
# ciphers.append("".join([chr(ord('a') + l[i]) for i in range(26)]))
# ks.append(999999937)

# l = [i for i in range(26)]
# shuffle(l)
# words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(randint(1,20000))]))
# ciphers.append("".join([chr(ord('a') + l[i]) for i in range(26)]))
# ks.append(randint(1, 1000))

# l = [i for i in range(26)]
# shuffle(l)
# words.append("".join([chr(ord('a') + randint(0, 25)) for i in range(randint(1,20000))]))
# ciphers.append("".join([chr(ord('a') + l[i]) for i in range(26)]))
# ks.append(randint(1, 1000000000))

print(len(words))
assert(len(words) == len(ciphers) == len(ks))
for i in range(len(words)):
    print(words[i])
    print(ciphers[i])
    print(ks[i])