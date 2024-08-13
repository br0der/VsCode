f = open("tetris_large.in", 'r')
fo = open("../../../data/output.txt", 'w')

def input():
    return f.readline()

def print(s):
    fo.write(str(s) + '\n')

# Written by: Brady Aber
# UCF SI Camp 24: Contest 2
# 7/8/24
# tetris.py

for tc in range(int(input())):
    w, h = map(int, input().split())
    print((w*h)//4)