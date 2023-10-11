for tc in range(int(input())):
    s = input()
    i = 0
    out = ''
    vowels = {'a', 'e','i','o','u'}
    while i<len(s)-1:
        if s[i] in vowels:
            out+=s[i+1]
            i+=1
        i+=1
    print(out)