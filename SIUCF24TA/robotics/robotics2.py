def thing(trP, thP, tyP, r):

    if trP[0]*thP[0]*tyP[0]>r:
        return("DISQUALIFIED!")
    max = trP[0]*thP[0]*tyP[0]

    for a in reversed(range(len(trP))):
        '''if tyP[-1]*thP[-1]<max//trP[a]:
            #print(f"{tyP[-1]}*{thP[-1]}<{max}//{trP[a]}")
            #print("a")
            break'''
        for b in  reversed(range(len(thP))):
            '''if trP[a]*tyP[-1]<max//thP[b]:
                #print(f"{trP[a]}*{tyP[-1]}<{max}//{thP[b]}")
                #print("b")
                break'''
            for c in  reversed(range(len(tyP))):
                '''if trP[a]*thP[b]<max//tyP[c]:
                    #print(f"{trP[a]}*{thP[b]}<{max}/{tyP[c]}")
                    #print("c")
                    break'''

                if trP[a]*thP[b]*tyP[c]==r:
                    return(r)
                elif trP[a]*thP[b]*tyP[c]<r:
                    #print(trP[a]*thP[b]*tyP[c])
                    if trP[a]*thP[b]*tyP[c] > max:
                        max = trP[a]*thP[b]*tyP[c]

    return(max)



times =int(input())
for i in range(times):
    tr, th, ty, r = map(int, input().split())

    trP = list(map(int, input().split()))

    thP = list(map(int, input().split()))

    tyP = list(map(int, input().split()))
    trP.sort()
    thP.sort()
    tyP.sort()
    print(thing(trP, thP, tyP, r))

'''
lis = [1, 2, 3, 8, 9]
for i in reversed(range(len(lis))):
    print(lis[i])
'''