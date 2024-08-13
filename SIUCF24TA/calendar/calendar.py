from math import *
commonMultiple = lcm(7,30,365)

fi = open("calendar_small.in", 'r')
# fo = open("calendar_small.in", 'w')

# def print(s):
#     fo.write(str(s)+"\n")

def input():
    return fi.readline()

d = int(input().strip())

for i in range(d):
    n = int(input().strip())
    pictures = {(int(picture) % commonMultiple) for picture in input().split()}

    comboFound = False
    if 0 in pictures:
        comboFound = True
    for picture1 in pictures:
        if comboFound:
            break
        for picture2 in pictures:
            if ((picture1 + picture2) % commonMultiple) == 0:
                comboFound = True
                break
    if comboFound:
        print(":)")
    else:
        print(":(")