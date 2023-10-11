n = int(input())
bal = 0
mn = 0
for i in range(n):
    bal+=(int(input()))
    mn = min(mn, bal)
print(abs(mn))