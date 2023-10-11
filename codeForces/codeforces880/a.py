from collections import defaultdict
for tc in range(int(input())):
    n = int(input())
    count = defaultdict(int)
    l = list(map(int, input().split()))
    for robot in l:
        count[robot]+=1
    works = True
    for i in count.keys():
        if i!=0:
            if i-1 not in count.keys() or count[i-1]<count[i]:
                works = False
    print('YES' if works else 'NO')