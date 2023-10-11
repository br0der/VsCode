for tc in range(int(input())):
    n, k = map(int, input().split())
    out = (n+k-1)//k
    if (n-1)%k!=0:
        out+=1
    print(out)
    # arr = [0]*n
    # i = 0
    # untilOne = 0
    # out = 0
    # while arr[i]!=1:
    #     if untilOne==0:
    #         out+=2
    #         if i==(n-i-1):
    #             out-=1
    #             break
    #         arr[i]=1
    #         arr[n-i-1]=1
    #         untilOne=k
    #     untilOne-=1
    #     i+=1
    # print(out)