s = input()
cnt = 0
y = 0
for ch in s:
    if ch in {'a', 'e', 'i', 'o', 'u'}:
        cnt+=1
    if ch=='y':
        y+=1

print(cnt, cnt+y)