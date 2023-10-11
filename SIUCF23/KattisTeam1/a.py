n, cost = map(int, input().split())
t = []
for i in range(n):
    t.append(int(input()))
t.sort(reverse=True)
if len(t) == 0:
    print("YES")
else:
    time = t[0]
    for i in range(n-1):
        time -= cost
        
    print("YES" if time > 0 else "NO")