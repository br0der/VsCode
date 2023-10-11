s = input()
dp = [-1]*len(s)
M = 9302023

group = []
dp = []
np = []

out = 1
optimal = len(s)
idx = 0
while idx < len(s):
    if idx<=len(s)-3 and s[idx:idx+3] in {"one", "two", "six"}:
        group.append(2)
        idx+=2
    elif idx<=len(s)-4 and s[idx:idx+4] in {"zero", "four", "five", "nine"}:
        group.append(3)
        idx+=3
    elif idx<=len(s)-5 and s[idx:idx+5] in {"three", "seven", "eight"}:
        group.append(4)
        idx+=4
    elif len(group)!=0: 
        # print(len(group))
        if len(group)!=1:
            dp = [-1]*len(group)
            np = [-1]*len(group)
            dp[-1] = group[-1]
            dp[-2] = group[-2]
            np[-1] = 1
            np[-2] = 1
            
            for i in reversed(range(len(group)-2)):
                if i==len(group)-3:
                    dp[i] = dp[i+2]+group[i]
                    np[i] = 1
                else:
                    if dp[i+2] > dp[i+3]:
                        dp[i] = dp[i+2] + group[i]
                        np[i] = np[i+2]
                    elif dp[i+3] > dp[i+2]:
                        dp[i] = dp[i+3] + group[i]
                        np[i] = np[i+3]
                    else:
                        dp[i] = dp[i+3] + group[i]
                        np[i] = np[i+2] + np[i+3]

            a = dp[0]
            b = dp[1]
            if a > b:
                optimal -= a
                out *= np[0]
            elif b > a:
                optimal -= b
                out *= np[1]
            else:
                optimal -= a
                out *= np[0]+np[1]
                
            out%=M
        else:
            optimal-=group[0]
        group = []
        idx+=1
    else:
        idx+=1

print(optimal)
print(out)


