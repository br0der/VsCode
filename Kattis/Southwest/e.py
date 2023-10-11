a = input()
b = input()
ans = 1
for i in range(len(a)):
    if a[i]!=b[i]:
        ans*=2
print(ans)