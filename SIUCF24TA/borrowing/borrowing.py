fi = open("borrowing_small.in", 'r')
fo = open("borrowing_small.out", 'w')

def input():
    return fi.readline()

def print(s, end = '\n'):
    fo.write(str(s) + end)

# Written by: Brady Aber
# UCF SI Camp 2024
# 7/14/24
# borrowing.py
for tc in range(int(input())):
    n, k = map(int, input().split())

    people = list(map(int, input().split()))
    # Lets binary search the day that we run out of pens.

    lo = 0
    # Bigger than we need
    hi = 3*(10**9)
    ans = -1

    # I use an inclusive-inclusive binary search.
    while lo <= hi:
        mid = (lo+hi)//2
        taken = 0

        # Calculate at the end of this day, how many pens people will take
        for person in people:
            if person <= mid:
                taken += (mid - person + 1)

        
        if taken > k:
            # If you run out of pens on this day, save it as a potential answer, and move in.
            ans = mid
            hi = mid - 1
        else:
            lo = mid + 1

    print(ans)