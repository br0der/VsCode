# fi = open("robotics_large.in", 'r')
# fo = open("robotics_large.out", 'w')

# def input():
#     return fi.readline()

# def print(s, end = '\n'):
#     fo.write(str(s) + end)

# Written by: Brady Aber
# UCF SI Camp 2024
# 7/14/24
# robotics.py

for tc in range(int(input())):
    tr, th, ty, r = map(int, input().split())

    parts = []
    parts.append(list(map(int, input().split())))
    parts.append(list(map(int, input().split())))
    parts.append(list(map(int, input().split())))

    # Since order doesn't matter, sorting can only help!
    for part in parts:
        part.sort()
    
    # Storing our best combination so far
    best = -1

    # We will fix the first part.
    for part1 in parts[0]:
        extraSpace = r//part1

        # Since we can work out the the maximum the other two parts can multiply to, 
        # lets use two-pointer. One starting from the front and one coming from the back.
        # We will only increase i and decrease j.
        i = 0
        j = len(parts[2]) - 1
        while i < len(parts[1]) and j >= 0:

            # While j is too large, decrease j.
            while j>=0 and parts[1][i] * parts[2][j] > extraSpace:
                j-=1
            
            if j < 0:
                break

            best = max(best, part1*parts[1][i]*parts[2][j])
            # Increase i
            i+=1

    
    if best==-1:
        print("DISQUALIFIED!")
    else:
        print(best)