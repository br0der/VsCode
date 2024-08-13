for tc in range(int(input())):
    n = int(input())

    starts = []
    ends = []

    for i in range(n):
        start, end = map(int, input().split())
        starts.append(start)
        ends.append(end)
    starts.sort()
    ends.sort()
    i = 0
    j = 0

    meetingsGoingOn = 0

    napTimes = []

    while i < n and j < n:
        if ends[j] > starts[i]:
            i += 1
            meetingsGoingOn += 1
        else:
            j += 1
            meetingsGoingOn -= 1
        
        if meetingsGoingOn == 0:
            napTimes.append(starts[i] - ends[j-1])
    print(napTimes)
        
