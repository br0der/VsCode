lis = []

for i in range(1, 6):
    lis.append(i)

lis2 = [[1, 2], [3, 4], [5, 6]]

print(lis2)

lis3 = [[j for j in range(5)] for i in range(5)]
print(lis3)

b = 100
a = 'even' if b % 2 == 0 else 'odd'



print(a)