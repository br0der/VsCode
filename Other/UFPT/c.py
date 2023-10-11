from math import gcd

n, m = map(int, input().split())

nums = set()

for i in range(m):
    a, b = input().split()
    b = int(b)
    works = True
    if(a=="+"):
        if b in nums:
            print("Already on")
            continue
        for num in nums:
            if(gcd(num, b)!=1):
                print("Conflict with " + str(num))
                works = False
                break
        if(works):
            print("Success")
            nums.add(b)
    else:
        if not(b in nums):
            print("Already off")
            continue
        nums.remove(b)
        print("Success")
    