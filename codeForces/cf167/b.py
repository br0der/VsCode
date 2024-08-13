for tc in range(int(input())):
    s1 = input()
    s2 = input()
    mx = 0

    for i in range(len(s2)):
        j = i
        for k in range(len(s1)):
            if j == len(s2):
                break
            if s2[j]==s1[k]:
                j+=1
        mx = max(mx, j-i)
    print(len(s1) + len(s2) - mx)