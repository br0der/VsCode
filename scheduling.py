# events = [[0,6], [1,4], [3, 8], [5,10], [7,17], [9,12], [14,16]]
events = [[0,4],[1,7],[3,9],[7,12],[10,14],[11,17],[13,19],[18,27],[20,30],[22,25],[28,31]]
sl = list(range(0, len(events)))
# sl = sl + list(map(lambda x: -x, sl))
sl.sort(key=(lambda n: events[n][0]))

# Could be infinity, but the problem gives an n^2 bound so I can use that
MAX = (len(events))**2 + 1

# Number of supervisors
sups = []
# Earliest finishing point of unsupervised event
efu = MAX
# Current finishing point of supervisor
cfs = -1
# Latest finishing point of a potential supervisor
lfp = -1
# ID of best potential supervisor
idp = -1

# Loop over start and end points
for key in sl:
    i = key
    start = events[i][0]
    end = events[i][1]

    # Just passed the end of an unsupervised event
    if start > efu:
        efu = MAX
        sups.append(idp)
        cfs = lfp

    # Check if it's unsupervised
    if start > cfs:
        if end < efu:
            efu = end
    # Check if it's a new potential supervisor
    if end > lfp:
        lfp = end
        idp = i
    print(f"{i}: {events[i]} -- {cfs}, {idp}:{lfp}, {'MAX' if efu == MAX else efu}")

if efu != MAX:
    sups.append(idp)

print("\n".join(list(map(lambda x: f"{x} : {events[x]}", sups))))