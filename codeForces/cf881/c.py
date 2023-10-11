from math import log2


for tc in range(int(input())):
    n = int(input())
    total = 1
    while n!=1:
        total+=n
        n//=2
    print(total)