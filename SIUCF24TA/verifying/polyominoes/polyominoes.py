fi = open("tyler.in", "r")
# fo = open("brady.out", "w")

def input():
    return fi.readline()

# def print(s, end = '\n'):
#     fo.write(str(s) + end)

# Written by: Brady Aber
# UCF SI Camp 24
# 7/11/24
# polyominoes.py

mxPoly = 1<<64

# A nice way to print a polyomino
def prnt(n):
    for i in reversed(range(8)):
        for j in range(8):
            print('⬜' if n&((1<<(8*i))<<j) else '⬛', end = '')
        print("")
    print("")

# Bitwise shifts a polyomino up
def up(n, force=False):
    top = 1<<48
    if not force:
        for i in range(8):
            if n&top:
                return n
            top<<=1
    return n<<8

# Bitwise shifts a polyomino down
def down(n, force=False):
    bottom = 1<<8
    if not force:
        for i in range(8):
            if n&bottom:
                return n
            bottom<<=1
    return n >> 8

# Bitwise shifts a polyomino right
def right(n, force=False):
    side = 1<<6
    if not force:
        for i in range(8):
            if n&side:
                return n
            side<<=8
    return n<<1

# Bitwise shifts a polyomino left
def left(n, force=False):
    side = 1<<1
    if not force:
        for i in range(8):
            if n&side:
                return n
            side<<=8
    return n>>1

# Rotates a polyomino to the right
def rotateRight(n):
    newN = 0
    for i in range(8):
        for j in range(8):
            if n&1<<(8*j + 7-i):
                newN |= 1<<(8*i + j)
    return newN

# Horizontally flips a polyomino
def flipHorizontal(n):
    newN = 0
    for i in range(8):
        for j in range(8):
            if n&1<<(8*i + j):
                newN |= 1<<(8*i + 7-j)
    return newN

# Make a new polyomino in a certain direction given a function and its inverse
def createNewPolyominoes(n, f, finv):
    inv = finv(n)
    newSpaces = (f(inv, force=True)&(-inv - 1))
    newSpaces&=35604928818740736
    last = 1
    out = []
    for shift in range(64):
        if newSpaces&last:
            out.append(last|inv)
        last <<= 1
    return out

# Canonicalizes a polyomino, by moving it to the top left, rotating and flipping it
# Takes the min of all 8 of these, which will guarentee all 8 give the same number
def canonicalization(n):
    flippedN = flipHorizontal(n)
    canons = []
    canons.append(n)
    canons.append(flippedN)
    for i in range(3):
        n = rotateRight(n)
        flippedN = rotateRight(flippedN)
        canons.append(n)
        canons.append(flippedN)
    for i in range(len(canons)):
        
        leftShift = left(canons[i])
        while leftShift!=canons[i]:
            canons[i] = leftShift
            leftShift = left(leftShift)

        downShift = up(canons[i])
        while downShift!=canons[i]:
            canons[i] = downShift
            downShift = up(downShift)
    return min(canons)

# Checks for a 2x2 square throughout the polyomino
def containsSquare(n):
    square = 394752
    # print(square)
    for i in range(6):
        tempsquare = square
        for j in range(6):
            if n&tempsquare == tempsquare:
                return True
            tempsquare <<= 1
        square<<=8
    return False


polyominoes = [[], [right(up(1))]]

# n = int(input())
n = 5
# print(1)
# Compute them in order
for i in range(2, n+1):
    nextGen = set()

    # For all the polyominoes, add the canonicalization of what they can turn into
    for poly in polyominoes[i-1]:
        newAdds = []
        newAdds.extend(createNewPolyominoes(poly, up, down))
        newAdds.extend(createNewPolyominoes(poly, down, up))
        newAdds.extend(createNewPolyominoes(poly, right, left))
        newAdds.extend(createNewPolyominoes(poly, left, right))

        # Add the canonicalized versions of all polyominoes to the set 
        for poly in newAdds:
            c = canonicalization(poly)
            if not containsSquare(c):
                # The set makes sure there are no duplicate canonicalizations
                nextGen.add(c)

    polyominoes.append(list(nextGen))
    # print(len(polyominoes[-1]))
# s = set(polyominoes[11])
# tyler = set()
# for i in range(6655):
#     poly = 0
#     for j in range(8):
#         inp = input().strip()
#         for k in range(8):
#             if inp[k]=='1':
#                 poly += 1<<k
#         poly<<=8
#     poly>>=8
#     input()
#     poly = canonicalization(right(down(poly)))
#     tyler.add(poly)
#     # prnt(poly)

# for poly in s:
#     if poly not in tyler:
#         print(poly)

prnt(569566283695104)
prnt(565157802047488)
prnt(565174949408768)
prnt(578377618046976)
prnt(569600576587776)
prnt(565157600590848)