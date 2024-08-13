from collections import defaultdict
from heapq import heappush, heappop

f = open("fridge_sample.in", "r")
def input():
    return f.readline()

cases = int(input())
assert(1 <= cases <= 20)
for tc in range(cases):
    n = int(input())
    assert(2 <= n <= 100000)
    heap = []
    # A map from the expiration date to all food expiring on that day
    items = defaultdict(list)

    # Add all food values to the map accordingly
    for i in range(n):
        expiration, value = map(int, input().split())
        assert(1 <= expiration <= n - 1)
        assert(1 <= value <= 100000)
        items[expiration].append(value)

    canEat = []
    eaten = 0
    # From the last day to the first, eat the most valuable food on that day.
    for i in reversed(range(1, n)):
        for value in items[i]:
            # Need to add the negative to the heap, because python uses
            # a min heap (when you remove from it, it removes the smallest.)
            heappush(canEat, -value)
        
        if len(canEat) > 0:
            # Because it finds the smallest value, it actually finds the
            # largest in magnitude. It subtracts the negative number from 
            # the total.
            eaten -= heappop(canEat)
        
    print(eaten)