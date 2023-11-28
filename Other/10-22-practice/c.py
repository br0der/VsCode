n, m = map(int, input().split())
A = [0]*m
B = [0]*m
total = 0
for i in range(n):
    idx, aa, bb = map(int, input().split())
    A[idx-1]+=aa
    B[idx-1]+=bb
    total+=aa
    total+=bb
diffa = 0
diffb = 0
for i in range(m):
    avg = ((A[i]+B[i])//2)+1
    if(A[i]>B[i]):
        print("A", A[i]-avg, B[i])
        diffa+=A[i]-avg
        diffb+=B[i]
    else:
        print("B", A[i], B[i]-avg)
        diffa+=A[i]
        diffb+=B[i]-avg

print(abs(diffa-diffb)/total)