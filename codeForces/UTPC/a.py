n = int(input())
people = []
for j in range(n):
    lis = input().split()
    for i in range(1, 5):
        lis[i] = -int(lis[i])
    lis.reverse()
    people.append(lis)
people.sort()
for person in people:
    print(person[4])
