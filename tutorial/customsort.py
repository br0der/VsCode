fi = open("../data/input.txt", 'r')
fo = open("../data/output.txt", 'w')

# def print(str):
#     fo.write()

# def input():
#     fo.read()

# n = int(input())


# a = list(map(int, input().split()))

def func(y):
    y[0]

# lis.sort(key= lambda x: x[1])
# a.sort(key= lambda y: y)
# print(a)

lis10 = [[1, 2], [9, 1], [2, 2], [5, 9], [5, 0]]

lis10.sort(key=lambda x: sum(x))
lis10.sort(key=lambda x: x[0])

print(lis10)