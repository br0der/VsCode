for tc in range(int(input())):
    all, tested = map(int, input().split())
    things = set()
    for i in range(all):
        things.add(input())
    for x in range(tested):
        things.remove(input())
    broken = sorted(things, key = lambda x : x.lower())
    for i in range(len(things)):
        print(broken[i])
print(ord('a'), ord('A'))