import sys

# Very important: setting the recursion limit in python.
# Could have been done iteravely but Brady likes recursive :)
sys.setrecursionlimit(1010)

# Good if you want to take in input from a file
f = open("faketree_large.in", "r")
def input():
    return f.readline()

# Also very important I made these global, so that my function could access it.
dp = []
parts = []

# Makes reading a little easier
class Part:
    def __init__(self, l, w, h):
        self.length = l
        self.width = w
        self.height = h

def func(i):
    # If you cannot use any parts, the best score you can get it 0.
    if i >= len(dp):
        return 0
    
    # If its not computed, lets compute it!
    if dp[i] == -1:
        dp[i] = parts[i].height

        # Starting from the current part, you want to transition to any other possible future part.
        for j in range(i + 1, len(parts)):

            # In the beginning, we ordered the parts so the length was always longer than the
            # width. Since all parts were aligned this way, we can just consider case (a).

            # It is also valid to just check fo case (b), which wouldnt require this assumption.
            if parts[j].length <= parts[i].length and parts[j].width <= parts[i].width:
                # If we get a better output by transitioning to this part, then change our output.
                dp[i] = max(dp[i], func(j) + parts[i].height)

    return dp[i]


for tc in range(int(input())):
    n = int(input())
    parts = []

    # Take in input
    for i in range(n):
        l, w, h = map(int, input().split())

        # Ordering the part with the maximum length/width first and the minimum
        # makes comparting two parts easier later on.
        parts.append(Part(max(l, w), min(l, w), h))

    # Setup the DP
    dp = [-1 for i in range(n)]

    # Fill the dp table
    for i in range(n):
        func(i)

    # Print the maximum out of any starting position
    print(max(dp))