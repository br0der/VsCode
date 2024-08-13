# fi = open("two_large.in", 'r')
# fo = open("out.out", 'w')
# def input():
#     return fi.readline()
# def print(s):
#     fo.write(str(s) + '\n')

# Written by: Brady Aber
# UCF SI Camp 2024
# 07/14/24
# two.py

# Some pre-computing of the first 1,000,000 powers of two under a PRIME mod
MOD = 10000000007
mods = dict()
curr = 1
for i in range(1000001):
    curr%=MOD
    mods[curr] = i
    curr*=2

# It can be proven that no two powers of two under 10^6 will have conflicting 
# modulos under a prime mod, so there is a one-to-one relationship between a 
# power of two under mod, and the exponent it was raised to.

# Note: I think its more annoying to prove that all powers of two won't have
# conflicting modulos under a non-prime mod, which Thomas used in his two.cpp
# solution. This makes my solution better than his!

tcs = int(input())
for tc in range(tcs):
    num = input().strip()

    # Now we calculate the very big integer we are given (a string) under mod
    curr = int(num[0])
    for i in range(1, len(num)):
        curr*=10
        curr+=int(num[i])
        curr%=MOD

    # Access what we have pre-computed
    print(mods.get(curr, -1))

