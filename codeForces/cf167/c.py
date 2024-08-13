for tc in range(int(input())):
    m1 = 0
    m2 = 0
    ones = 0
    nones = 0
    l = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(len(a)):
        if a[i] == b[i]:
            if a[i] == -1:
                nones+=1
            elif a[i] == 1:
                ones+=1
        elif a[i] == 1:
            m1+=1
        elif b[i] == 1:
            m2+=1
    if m1 > m2:
        temp = m1
        m1 = m2
        m2 = temp
    add = min(abs(m1-m2), ones)
    m1 += add
    ones -= add
    sub = min(abs(m1-m2), nones)
    m2 -= sub
    nones -= sub
    # print(m1, m2, ones, nones)
    if m1 == m2:
        diff = ones-nones
        if diff >= 0:
            print(int(m1 + diff/2))
        else:
            if diff%2 == 1:
                diff -= 1
            print(int(m1 + diff/2))
    else: 
        print(min(m1, m2))