for tc in range(int(input())):
    s = input()
    out = ''
    for i in range(len(s)//7):
        n = 0
        for j in range(7):
            if s[i*7 + j] in {'G', 'C'}:
                n^=(1<<(6-j))
        # print(bin(n))
        out+=(chr(n))
    print(out)