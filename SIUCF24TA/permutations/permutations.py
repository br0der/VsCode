f = open("permutations_large.in", 'r')
fo = open("permutations_large2.out", 'w')

def input():
    return f.readline()

def print(s):
    fo.write(str(s) + '\n')

cases = int(input())
for case in range(cases):
    n = int(input())
    arr = list(map(int,input().split()))
    assert(len(set(arr))==(len(arr)))
    for elem in arr: assert(1<=elem<=n)
    #compute Nth Triangle number so you don't need to sum the permutation
    permutationSum = (n*(n+1))//2
    #don't actually need a dictionary but want to make sure it passes
    delta = dict()
    for i in range(n):
        #weird mod arithmatic to make sure that distances to the left and to the right are canonicalized to be the same
        myShift = ((arr[i])-i)%n 
        if(myShift < 0):
            myShift = (n+myShift)%n
        if(myShift in delta):
            delta[myShift] += arr[i]
        else:
            delta[myShift] = arr[i]
    ans = 0
    for key in delta:
        ans = max(ans,delta[key])
    print(permutationSum-ans)