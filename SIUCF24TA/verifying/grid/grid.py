fi = open("grid_small.in", "r")
fo = open("out.out", "w")

def input():
    return fi.readline()

def print(s):
    fo.write(s + '\n')

# Written by: Brady Aber
# UCF SI Camp: Contest 3
# 7/10/24
# grid.py

# A hellish way to do this problem for sure.
# Look at the cpp solution for a much easier solution

# The main idea of this is to go through each grid top to bottom first,
# then left to right, turning every cell 0 (Black), and flipping the
# cell below it. Then on the bottom row, go left to right turning all cells
# to 0, so that the entire grid is black except for the bottom right cell.

# Compare the bottom right cell in grid1 and grid2, and if they are different
# it is impossible!
c = 0
for tc in range(int(input())):
    c+=1
    n = int(input())
    assert(1<=n<=3)
    g1 = []
    for i in range(n):
        s = input().strip()
        
        assert(sum([i=='B' or i=='W' for i in s])==n)
        g1.append([0 if s[j]=='B' else 1 for j in range(n)])
        assert(len(g1[-1])==n)
    assert(len(g1)==n)
    
    input()
    g2 = []
    for i in range(n):
        s = input().strip()

        assert(sum([i=='B' or i=='W' for i in s])==n)
        g2.append([0 if s[j]=='B' else 1 for j in range(n)])
        assert(len(g2[-1])==n)
    assert(len(g2)==n)
    # Turn every row except the bottom row black
    for i in range(n-1):
        for j in range(n):
            if g1[i][j] == 1:
                g1[i][j] = 0
                g1[i+1][j] = 1 if g1[i+1][j]==0 else 0
            if g2[i][j] == 1:
                g2[i][j] = 0
                g2[i+1][j] = 1 if g2[i+1][j]==0 else 0
    # Turn the bottom row black, except for the bottom right (maybe)
    for j in range(n - 1):
        if g1[-1][j] == 1:
            g1[-1][j] = 0
            g1[-1][j + 1] = 1 if g1[-1][j+1]==0 else 0
        if g2[-1][j] == 1:
            g2[-1][j] = 0
            g2[-1][j + 1] = 1 if g2[-1][j+1]==0 else 0
    
    # If the bottom rights are different, it is impossible.
    if g1[-1][-1] == g2[-1][-1]:
        print("grid problems <3")
    else:
        print("grid problems :(")

assert(1 <= c <= 20)