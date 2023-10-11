for tc in range(int(input())):
    v, e, l = list(map(int, input().split()))
    num = ((v/(e - l)) * l)
    print(int((num + 0.5)//1))