s = ""

import sys

sys.setrecursionlimit(1000000)




for tc in range(int(input())):
    s = input()
    possible = []
    # print(s[0])
    # print(func(1, 8, -1))
    for i in range(1, min(len(s)+1, 6)):
        
        # ans = -2
        idx = i
        last = int(s[0:i])
        skipped = -1
        while idx<len(s):
            # print(i, idx, last, skipped)
            if idx+len(str(last+1))<=len(s):
                if int(s[idx:idx+len(str(last+1))]) == last+1:
                    temp = len(str(last+1))
                    last = int(s[idx:idx+len(str(last+1))])
                    idx+=temp
                    

                    continue
                    # a = func(idx+len(str(last+1)), int(s[idx:idx+len(str(last+1))]), skipped)
                    # if a!=-2: 
                    #     return a
            if idx+len(str(last+2))<=len(s):
                if int(s[idx:idx+len(str(last+2))]) == last+2:
                    if (skipped==-1):
                        temp = last+1
                        last = int(s[idx:idx+len(str(last+2))])
                        idx = idx+len(str(temp+1))
                        skipped = temp
                        continue
                        # a = func(idx+len(str(last+2)), int(s[idx:idx+len(str(last+2))]), last+1)
                        # if a!=-2:
                        #     return last+1
            skipped = -2
            break
        ans = skipped
        # print(ans)
        if ans==-2: continue
        elif ans==-1:
            num = int(s[:i])
            idx = i
            while(idx<len(s)):
                num+=1
                idx+=len(str(num))
            # print(num)
            if int(s[:i])-1 >= 1:
                possible.append(int(s[:i])-1)
                # print(ans, int(s[:i])-1)
            if num+1 <= 99999:
                possible.append(num+1)
                # print(ans, num+1)
        else:
            possible.append(ans)
    print(len(possible))
    possible.sort()
    for i in range(len(possible)):
        print(possible[i], end = ' ')
    print()